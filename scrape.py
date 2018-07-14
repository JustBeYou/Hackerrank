import requests
import lxml
import lxml.html
import re
import os

# constants
DASHBOARD_URL = "https://www.hackerrank.com/dashboard"
LOGIN_URL = "https://www.hackerrank.com/auth/login"


class HackerRank(object):
    session = None
    headers = {
        "Host": "www.hackerrank.com",
        "User-Agent": "Mozilla/5.0 (X11; Linux x86_64; rv:61.0) Gecko/20100101 Firefox/61.0",
        "Accept-Language": "en-US,en;q=0.5",
        "Accept-Encoding": "gzip, deflate, br",
        "X-CSRF-Token": None
    }
    csrf_token = None

    def __init__(self, username, password):
        self.username = username
        self.password = password

    def createSession(self):
        self.session = requests.session()

        # get some cookies and the CSRF token
        resp = self.session.get(DASHBOARD_URL, headers = self.headers).text
        found = re.search(r'meta content=\"(.*)\" name=\"csrf\-token\"', resp)
        self.csrf_token = found.group(1)

        # login
        self.headers["X-CSRF-Token"] = self.csrf_token
        self.headers["Accept"] = "application/json"
        self.headers["Content-Type"] = "application/json"
        data = {
            "login" : self.username,
            "password" : self.password,
            "remember_me" : "false"
        }
        resp = self.session.post(LOGIN_URL, headers = self.headers, json = data)
        if 'Authorised Succesfully' not in resp.json()["messages"]:
            raise Exception("Login failed.")

    def getSession(self):
        return self.session

    def scrapeAlgorithms(self):
        # get solved challenges
        url = "https://www.hackerrank.com/rest/contests/master/tracks/algorithms/challenges?offset=0&limit=500&filters[status][]=solved&track_login=true"
        data = self.session.get(url).json()

        problems = set()
        for e in data["models"]:
            problems.add(e["slug"])

        # get code for each challenge
        submission_url = "https://www.hackerrank.com/rest/contests/master/challenges/{}/submissions/?offset=0&limit=100"
        code_url = "https://www.hackerrank.com/rest/contests/master/challenges/{}/submissions/{}"

        ret = []
        for problem in problems:
            resp = self.session.get(submission_url.format(problem)).json()

            best_submission = 0
            max_score = 0
            # get the best submission for the problem
            for submission in resp["models"]:
                submission["score"] = int(float(submission["score"]) * 100)
                if submission["score"] > max_score:
                    max_score = submission["score"]
                    best_submission = submission["id"]

            resp = self.session.get(code_url.format(problem, best_submission)).json()
            code = resp["model"]["code"]

            print ("[INFO] Scraped {}".format(problem))
            ret.append((problem + "." + resp["model"]["language"], code))

        return ret

class Commiter(object):
    def __init__(self, files):
        self.files = files

    def commit(self):
        for elem in self.files:
            filename = elem[0]
            content  = elem[1]

            print ("[INFO] Write to file {}".format(filename))
            # write content
            with open(filename, "w") as f:
                f.write(content)
                f.flush()

            # commit
            add_command = 'git add {}'.format(filename)
            commit_command = 'git commit -m "Add solution for {}"'.format(filename.split(".")[0])
            print (add_command)
            os.system(add_command)
            print (commit_command)
            os.system(commit_command)


hr = HackerRank("LittleWho", "***")
hr.createSession()
data = hr.scrapeAlgorithms()
c = Commiter(data)
c.commit()
