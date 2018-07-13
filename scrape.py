import requests
import lxml
import lxml.html
import re

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

    def getSession(self):
        return self.session

    def scrapeAlgorithms(self):
        url = "https://www.hackerrank.com/rest/contests/master/tracks/algorithms/challenges?offset=0&limit=500&filters[status][]=solved&track_login=true"
        data = self.session.get(url).json()

        problems = set()
        for e in data["models"]:
            problems.add(e["slug"])

        url = "https://www.hackerrank.com/challenges/{}/submissions"
        for problem in problems:
            resp = self.session.get(url.format(problem)).text
            tree = lxml.html.fromstring(resp)
            link = "https://hackerrank.com" + tree.xpath('//div[@class="ellipsis submission-result"]')[0][0].get('href')
            print (link)

hr = HackerRank("LittleWho", "***")
hr.createSession()
data = hr.scrapeAlgorithms()
