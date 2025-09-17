import time
from selenium import webdriver
from selenium.webdriver.common.by import By
from selenium.webdriver.support.ui import WebDriverWait, Select
from selenium.webdriver.chrome.service import Service
from selenium.webdriver.support import expected_conditions as EC
from selenium.common.exceptions import NoSuchElementException, WebDriverException
import chromedriver_autoinstaller

# Automatically install the correct ChromeDriver version
chromedriver_autoinstaller.install()

# Configure WebDriver
service = Service()
options = webdriver.ChromeOptions()
options.add_argument("--allow-insecure-localhost")
options.add_argument("--ignore-certificate-errors")
options.add_argument("--headless") 
options.add_argument("--no-sandbox")
options.add_argument("--disable-dev-shm-usage")

# Replace with your IIT Madras credentials
USERNAME = "cs24b064"
PASSWORD = "BjwwV57G8ye"
PREFERRED_MESS = "Vindhiya"  # Replace with the name of the mess you want

def is_preference_saved(driver):
    try:
        confirmation_message = driver.find_element(By.XPATH, "//*[contains(text(), 'Your preference is already saved')]")
        return confirmation_message.is_displayed()
    except NoSuchElementException:
        return False

def automate_mess_preference():
    while True:
        try:
            driver = webdriver.Chrome(service=service, options=options)
            driver.get("https://hosteldine.iitm.ac.in/iitmhostel/login.do?method=userlogin&loginType=student")
            print("Webpage opened\n")
            # Step 1: Wait for login fields to appear and enter credentials
            print("Login page loaded\n")
            username_field = WebDriverWait(driver, 10).until(
                EC.presence_of_element_located((By.NAME, "username"))
            )
            password_field = driver.find_element(By.NAME, "password")
            submit_button = driver.find_element(By.XPATH, "//button[@type='submit']")

            username_field.send_keys(USERNAME)
            password_field.send_keys(PASSWORD)
            submit_button.click()
            print("Login complete\n")

            # Step 2: Wait for the mess preference button to be clickable
            mess_preference_button = WebDriverWait(driver, 10).until(
                EC.element_to_be_clickable((By.LINK_TEXT, "Mess Preference"))
            )
            mess_preference_button.click()

            # Step 3: Wait for the mess dropdown to be visible
            mess_dropdown = Select(WebDriverWait(driver, 10).until(
                EC.presence_of_element_located((By.NAME, "mess_dropdown"))
            ))
            mess_dropdown.select_by_visible_text(PREFERRED_MESS)

            # Step 4: Click "Save My Preference"
            save_button = WebDriverWait(driver, 10).until(
                EC.element_to_be_clickable((By.XPATH, "//button[contains(text(), 'Save My Preference')]"))
            )
            save_button.click()

            # Step 5: Check if preference is saved
            if is_preference_saved(driver):
                print("Your preference is already saved!")
                break

        except WebDriverException as e:
            print(f"Error occurred: {e}. Retrying...")

        finally:
            driver.quit()
            time.sleep(5)

# Run the automation
automate_mess_preference()
