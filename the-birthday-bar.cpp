#include <bits/stdc++.h>

using namespace std;

int solve(int n, vector < int > s, int d, int m){
    // Complete this function
    
    vector<int> sums(s.size(), 0);
    sums[0] = s[0];
    
    for (int i = 1; i < s.size(); i++) {
        sums[i] = sums[i - 1] + s[i];
    }
    
    int ret = 0;
    for (int i = 0; i + m - 1 < s.size(); i++) {
        if (i == 0) {
            if (sums[i + m - 1] == d) ret++;
        } else if (sums[i + m - 1] - sums[i - 1] == d) {
            ret++;
        }
    }
    
    return ret;
}

int main() {
    int n;
    cin >> n;
    vector<int> s(n);
    for(int s_i = 0; s_i < n; s_i++){
       cin >> s[s_i];
    }
    int d;
    int m;
    cin >> d >> m;
    int result = solve(n, s, d, m);
    cout << result << endl;
    return 0;
}
