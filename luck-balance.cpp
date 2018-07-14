#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

typedef pair<int, int> contest;

struct sort_contests {
    bool operator() (contest A, contest B) {
        return A.first > B.first;
    }
};

int main() {
    int n, k;
    cin >> n >> k;
    
    vector<contest> contests(n);
    for (int i = 0; i < n; i++) {
        cin >> contests[i].first >> contests[i].second;
    }
    sort(contests.begin(), contests.end(), sort_contests());
    
    int luck = 0;
    for (int i = 0; i < n; i++) {
        if (contests[i].second) {
            if (k) {
                luck += contests[i].first;
                k--;
            } else {
                luck -= contests[i].first;
            }
        } else {
            luck += contests[i].first;
        }
    }
    cout << luck << endl;
    
    return 0;
}
