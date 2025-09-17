
from __future__ import print_function
from mbientlab.metawear import MetaWear, libmetawear, parse_value
from mbientlab.metawear.cbindings import *
from time import sleep
from threading import Thread
import sys
import numpy as np
import imufusion
import datetime

if sys.version_info[0] == 2 :
    range = xrange

class State:
    def __init__(self, device):
        self.device = device
        self.samples = 0
        self.acc_latest = None
        self.gyro_latest = None
        self.q = np.array([1.0, 0.0, 0.0, 0.0])
        self.sampleRate = 50.0

        self.ahrs = imufusion.Ahrs()
        self.ahrs.settings = imufusion.Settings(
            imufusion.CONVENTION_NWU,  # Frame convention (NWU = X north, Y west, Z up)
            1.0,  # gyro_gain= Trust gyroscope angular rate
            0.01, # 0.01 to 0.05   acc_bias_gain =Adjust slowly for 2g range, stable environments
            10.0, # acc_rejection=2g max, so reject accel when >3 m/s² from 1g norm
            10.0,  #  gyro_rejection= 250 dps max (~4.36 rad/s), 3 rad/s is moderate
            int(5 * self.sampleRate) #rejection_timeout
        )

        self.output_file = open(f"robot_arm_dynamic_{self.device.address.replace(':', '')}_10.csv", "w")
        self.output_file.write("timestamp,acc_x,acc_y,acc_z,gyro_x,gyro_y,gyro_z,w,x,y,z\n")

        self.accCallback = FnVoid_VoidP_DataP(self.acc_data_handler)
        self.gyroCallback = FnVoid_VoidP_DataP(self.gyro_data_handler)

    def acc_data_handler(self, ctx, data):
        acc = parse_value(data)
        self.acc_latest = np.array([acc.x, acc.y, acc.z])
        self.try_fuse()

    def gyro_data_handler(self, ctx, data):
        gyro = parse_value(data)
        self.gyro_latest = np.radians([gyro.x, gyro.y, gyro.z])  # Convert deg/s to rad/s

        self.try_fuse()

    def try_fuse(self):
        if self.acc_latest is not None and self.gyro_latest is not None:
            self.ahrs.update_no_magnetometer(self.gyro_latest, self.acc_latest, 1.0 / self.sampleRate)
            q = self.ahrs.quaternion
            self.q = np.array([q.w, q.x, q.y, q.z])
            timestamp = datetime.datetime.now().isoformat()
            self.output_file.write(f"{timestamp},{self.acc_latest[0]},{self.acc_latest[1]},{self.acc_latest[2]},"
                                   f"{np.degrees(self.gyro_latest[0])},{np.degrees(self.gyro_latest[1])},{np.degrees(self.gyro_latest[2])},"
                                   f"{q.w},{q.x},{q.y},{q.z}\n")
            print(f"{self.device.address} - Quaternion: {self.q}")
            self.samples += 1
            self.acc_latest = None
            self.gyro_latest = None

    def close(self):
        self.output_file.close()

# ---------- LED Utility Functions ----------

def set_led_pattern(device, color, intensity, repeat):
    pattern = LedPattern(repeat_count=repeat, delay_ms=0, high_time_ms=500, pulse_duration_ms=1000,
                         high_intensity=intensity, low_intensity=0)
    if color == 'green':
        libmetawear.mbl_mw_led_load_preset_pattern(pattern, LedPreset.SOLID)
        libmetawear.mbl_mw_led_write_pattern(device.board, pattern, LedColor.GREEN)
    elif color == 'blue':
        libmetawear.mbl_mw_led_load_preset_pattern(pattern, LedPreset.BLINK)
        libmetawear.mbl_mw_led_write_pattern(device.board, pattern, LedColor.BLUE)
    elif color == 'red':
        libmetawear.mbl_mw_led_load_preset_pattern(pattern, LedPreset.SOLID)
        libmetawear.mbl_mw_led_write_pattern(device.board, pattern, LedColor.RED)
    libmetawear.mbl_mw_led_play(device.board)

def stop_led(device):
    libmetawear.mbl_mw_led_stop_and_clear(device.board)

# ---------- Data Collection Function ----------

def setup_and_collect_data(state, duration=15):  #static=10sec ,dynamic=15 sec
    print(f"Setting up device {state.device.address}")

    # Green LED during setup
    set_led_pattern(state.device, 'green', 31, 0)

    libmetawear.mbl_mw_settings_set_connection_parameters(state.device.board, 7.5, 7.5, 0, 6000)
    sleep(1.5)

    # Configure accelerometer
    libmetawear.mbl_mw_acc_bmi270_set_odr(state.device.board, AccBmi270Odr._50Hz)
    libmetawear.mbl_mw_acc_bosch_set_range(state.device.board, AccBoschRange._2G)
    libmetawear.mbl_mw_acc_write_acceleration_config(state.device.board)

    # Configure gyroscope
    libmetawear.mbl_mw_gyro_bmi270_set_range(state.device.board, GyroBoschRange._250dps)
    libmetawear.mbl_mw_gyro_bmi270_set_odr(state.device.board, GyroBoschOdr._50Hz)
    libmetawear.mbl_mw_gyro_bmi270_write_config(state.device.board)

    # Stop green LED after setup
    stop_led(state.device)

    # Subscribe
    acc = libmetawear.mbl_mw_acc_get_acceleration_data_signal(state.device.board)
    libmetawear.mbl_mw_datasignal_subscribe(acc, None, state.accCallback)

    gyro = libmetawear.mbl_mw_gyro_bmi270_get_rotation_data_signal(state.device.board)
    libmetawear.mbl_mw_datasignal_subscribe(gyro, None, state.gyroCallback)

    # Blue LED blinking during data collection
    set_led_pattern(state.device, 'blue', 31, 0)

    # Start sampling
    libmetawear.mbl_mw_acc_enable_acceleration_sampling(state.device.board)
    libmetawear.mbl_mw_acc_start(state.device.board)
    libmetawear.mbl_mw_gyro_bmi270_enable_rotation_sampling(state.device.board)
    libmetawear.mbl_mw_gyro_bmi270_start(state.device.board)

    print(f"Started data collection on {state.device.address}")
    sleep(duration)

    # Stop sampling
    libmetawear.mbl_mw_acc_stop(state.device.board)
    libmetawear.mbl_mw_acc_disable_acceleration_sampling(state.device.board)
    libmetawear.mbl_mw_gyro_bmi270_stop(state.device.board)
    libmetawear.mbl_mw_gyro_bmi270_disable_rotation_sampling(state.device.board)

    # Unsubscribe
    libmetawear.mbl_mw_datasignal_unsubscribe(acc)
    libmetawear.mbl_mw_datasignal_unsubscribe(gyro)

    # Stop blue LED
    stop_led(state.device)

    # Red LED for reset/disconnect
    set_led_pattern(state.device, 'red', 31, 0)

    libmetawear.mbl_mw_debug_reset(state.device.board)
    sleep(3)
    libmetawear.mbl_mw_debug_disconnect(state.device.board)

    # Stop red LED
    stop_led(state.device)

    # Close file
    state.close()

# ------------------- MAIN -----------------------

if __name__ == "__main__":
    states = []

    for i in range(1, len(sys.argv)):
        d = MetaWear(sys.argv[i])
        d.connect()
        print("Connected to " + d.address + " over " + ("USB" if d.usb.is_connected else "BLE"))
        states.append(State(d))

    threads = []
    for s in states:
        t = Thread(target=setup_and_collect_data, args=(s,))
        t.start()
        threads.append(t)

    for t in threads:
        t.join()

    print("Total Samples Received")
    for s in states:
        print(f"{s.device.address} -> {s.samples}")
