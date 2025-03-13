from selenium import webdriver
from selenium.webdriver.common.by import By
from selenium.webdriver.chrome.service import Service
from selenium.webdriver.support.ui import WebDriverWait
from selenium.webdriver.support import expected_conditions as EC
import time
import os

# 저장 경로 설정
save_folder = r"C:\Users\freed\Desktop\DataScience\24-2\PROGRAMMING_Practice_for_data_science_KTS\Problem_l3"
os.makedirs(save_folder, exist_ok=True)

# Selenium WebDriver 설정
service = Service(r"C:\Users\freed\.cache\selenium\chromedriver\win64\130.0.6723.116\chromedriver.exe")
options = webdriver.ChromeOptions()
options.add_argument("--start-maximized")
driver = webdriver.Chrome(service=service, options=options)
wait = WebDriverWait(driver, 15)

# GeeksforGeeks 로그인 페이지로 이동
driver.get("https://auth.geeksforgeeks.org/")

# 이메일과 비밀번호 입력
wait.until(EC.presence_of_element_located((By.ID, "luser"))).send_keys("freebglee@gmail.com")
driver.find_element(By.ID, "password").send_keys("Zkfxhl1!")

# 로그인 버튼 클릭
try:
    login_button = wait.until(EC.element_to_be_clickable((By.XPATH, "//button[contains(text(), 'Sign In')]")))
    login_button.click()
except Exception as e:
    print("로그인 버튼을 찾을 수 없습니다:", e)
    driver.quit()

# 로그인 성공 후 문제 목록 페이지로 이동
time.sleep(5)
problem_list_url = "https://www.geeksforgeeks.org/explore?page=1&difficulty=Medium,Hard&sortBy=submissions"
driver.get(problem_list_url)
time.sleep(5)

# 스크롤을 통해 전체 페이지 로드
SCROLL_PAUSE_TIME = 2
last_height = driver.execute_script("return document.body.scrollHeight")

while True:
    driver.execute_script("window.scrollTo(0, document.body.scrollHeight);")
    time.sleep(SCROLL_PAUSE_TIME)
    new_height = driver.execute_script("return document.body.scrollHeight")
    if new_height == last_height:
        break
    last_height = new_height

# 문제 목록에서 각 문제의 링크 수집
problem_links = driver.find_elements(By.XPATH, "//a[contains(@href, '/problems/')]")
print(f"총 {len(problem_links)}개의 문제를 발견했습니다.")

for index, link in enumerate(problem_links):
    # 문제 페이지로 이동
    try:
        problem_title = link.text
        problem_url = link.get_attribute("href")
        print(f"{index + 1}. {problem_title} - {problem_url}")

        driver.execute_script("window.open(arguments[0]);", problem_url)
        driver.switch_to.window(driver.window_handles[1])
        time.sleep(3)

        # 문제 설명 추출
        problem_title_text = wait.until(EC.presence_of_element_located((By.TAG_NAME, "h1"))).text
        description_element = driver.find_element(By.CLASS_NAME, "problem-statement")
        description = description_element.text if description_element else "No description available"

        # Editorial 페이지로 이동하여 솔루션 가져오기
        try:
            editorial_button = driver.find_element(By.LINK_TEXT, "Editorial")
            editorial_button.click()
            time.sleep(3)

            yes_button = wait.until(EC.element_to_be_clickable((By.XPATH, "//button[text()='Yes']")))
            yes_button.click()
            time.sleep(2)

            # 솔루션 코드 추출
            solution_elements = driver.find_elements(By.CLASS_NAME, "language-python")
            python_solution = solution_elements[0].text if solution_elements else "No Python solution available"

            solution_elements = driver.find_elements(By.CLASS_NAME, "language-cpp")
            cpp_solution = solution_elements[0].text if solution_elements else "No C++ solution available"
        except Exception as e:
            print(f"Editorial 페이지에 접근할 수 없습니다: {e}")
            python_solution = "Premium content - Not accessible"
            cpp_solution = "Premium content - Not accessible"

        # 파일 저장
        safe_title = "".join([c for c in problem_title_text if c.isalnum() or c in (" ", "_")]).rstrip()
        with open(os.path.join(save_folder, f"{safe_title}_description.txt"), "w", encoding="utf-8") as desc_file:
            desc_file.write(description)
        with open(os.path.join(save_folder, f"{safe_title}_python_solution.py"), "w", encoding="utf-8") as py_file:
            py_file.write(python_solution)
        with open(os.path.join(save_folder, f"{safe_title}_cpp_solution.cpp"), "w", encoding="utf-8") as cpp_file:
            cpp_file.write(cpp_solution)

        print(f"Saved problem: {problem_title_text}")

        # 탭 닫기 및 원래 탭으로 돌아가기
        driver.close()
        driver.switch_to.window(driver.window_handles[0])
        time.sleep(3)
    except Exception as e:
        print(f"문제를 클릭하거나 정보를 수집하는 중 오류 발생: {e}")
        driver.close()
        driver.switch_to.window(driver.window_handles[0])

# 종료
driver.quit()
