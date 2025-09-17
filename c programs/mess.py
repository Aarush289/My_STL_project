import time
from selenium import webdriver
from selenium.webdriver.common.by import By
from selenium.webdriver.common.keys import Keys
from selenium.webdriver.support.ui import WebDriverWait
from selenium.webdriver.chrome.service import Service
from selenium.webdriver.support import expected_conditions as EC
from selenium.common.exceptions import NoSuchElementException, WebDriverException
import chromedriver_autoinstaller

# Automatically installs the correct ChromeDriver version
chromedriver_autoinstaller.install()

# Configure WebDriver
service = Service()
options = webdriver.ChromeOptions()
options.add_argument("--headless")  # Remove this if you want to see the browser
options.add_argument("--no-sandbox")
options.add_argument("--disable-dev-shm-usage")

# Replace with your IIT Madras credentials
USERNAME = "cs24b064"
PASSWORD = "BjwwV57G8ye"
PREFERRED_MESS = "Vindhiya"  # Replace with the name of the mess you want

# Function to check if preference is saved
def is_preference_saved(driver):
    try:
        # Look for the confirmation message
        confirmation_message = driver.find_element(By.XPATH, "//*[contains(text(), 'Your preference is already saved')]")
        return confirmation_message.is_displayed()
    except NoSuchElementException:
        return False

# Function to automate the workflow
def automate_mess_preference():
    while True:  # Retry loop
        try:
            # Open the browser and navigate to the login page
            driver = webdriver.Chrome(service=service, options=options)
            driver.get("https://hosteldine.iitm.ac.in")  # Update this with the actual URL

            # Step 1: Click "IIT M Student Login"
            wait = WebDriverWait(driver, 10)  # Wait for the options to load
            # iitm_login_button = driver.find_element(By.XPATH, "//span[text()='IITM Student login']")
            login_button = wait.until(
            EC.element_to_be_clickable((By.XPATH, "//a[@href='']"))
        )

            login_button.click()

            # Step 2: Enter username and password
            time.sleep(2)  # Wait for the login page to load
            username_field = driver.find_element(By.NAME, "username")
            password_field = driver.find_element(By.NAME, "password")
            submit_button = driver.find_element(By.XPATH, "//button[@type='submit']")

            username_field.send_keys(USERNAME)
            password_field.send_keys(PASSWORD)
            submit_button.click()

            # Step 3: Click "Mess Preference" option
            time.sleep(3)  # Wait for the main page to load
            mess_preference_button = driver.find_element(By.LINK_TEXT, "Mess Preference")
            mess_preference_button.click()

            # Step 4: Select the desired mess
            time.sleep(2)  # Wait for the mess preference page to load
            mess_dropdown = driver.find_element(By.NAME, "mess_dropdown")  # Adjust the name based on actual HTML
            mess_dropdown.send_keys(PREFERRED_MESS)

            # Step 5: Click "Save My Preference"
            save_button = driver.find_element(By.XPATH, "//button[contains(text(), 'Save My Preference')]")
            save_button.click()

            # Step 6: Check if preference is saved
            time.sleep(2)  # Wait for the response
            if is_preference_saved(driver):
                print("Your preference is already saved!")
                break  # Exit the loop if successful

        except WebDriverException as e:
            print(f"Error occurred: {e}. Retrying...")

        finally:
            driver.quit()
            time.sleep(5)  # Wait before retrying

# Run the automation
automate_mess_preference()
