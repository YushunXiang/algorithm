"""
爬取自己OJ通过的代码
"""
import requests
import os

os.makedirs("code-set", exist_ok=True)
headers = {
    "User-Agent": "Mozilla/5.0 (Windows NT 10.0; Win64; x64) AppleWebKit/537.36 (KHTML, like Gecko) Chrome/105.0.0.0 Safari/537.36"}
data = {
    "username": "2020302877+项裕顺",  # 填写用户名
    "password": "237012.xys1234"  # 填写密码
}
init_url = "http://10.216.217.131:9999/api/profile"
login_url = "http://10.216.217.131:9999/api/login"
problems_url = "http://10.216.217.131:9999/api/contest/problem?contest_id=3"
submission_url = "http://10.216.217.131:9999/api/contest_submissions"
code_url = "http://10.216.217.131:9999/api/submission"
submission_params = {
    "myself": 1,
    "result": None,
    "username": None,
    "page": 1,
    "contest_id": 3,
    "limit": 12,
    "offset": 0
}
language_suffix = {
    "C": ".c",
    "C++": ".cpp",
    "Java": ".java",
    "Python3": ".py",
    "Python2": ".py",
    "Golang": ".go"
}
session = requests.Session()
session.headers["User-Agent"] = headers["User-Agent"]
session.get(url=init_url)
session.headers["X-CSRFToken"] = session.cookies.get("csrftoken")
session.post(url=login_url, data=data)
problems = session.get(url=problems_url).json()
for problem in problems["data"]:
    if problem["my_status"] == 0:
        submissions = session.get(submission_url, params={**submission_params, "problem_id": problem["_id"]}).json()
        for submission in submissions["data"]["results"]:
            if submission["result"] == 0:
                subcode = session.get(code_url, params={"id": submission["id"]}).json()["data"]
                with open("code-set/" + subcode["problem"] + language_suffix[subcode["language"]], "w") as f:
                    f.write(subcode["code"])
                break
