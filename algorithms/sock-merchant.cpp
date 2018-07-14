#include <bits/stdc++.h>

using namespace std;

int sockMerchant(int n, vector <int> ar) {
    // Complete this function
    
    int matched = 0;
    map<int, bool> m;  
    for (auto &elem: ar) {
        if (m[elem]) {
            matched++;
            m[elem] = false;
        } else {
            m[elem] = true;
        }
    }
    
    return matched;
}

int main() {
    int n;
    cin >> n;
    vector<int> ar(n);
    for(int ar_i = 0; ar_i < n; ar_i++){
       cin >> ar[ar_i];
    }
    int result = sockMerchant(n, ar);
    cout << result << endl;
    return 0;
}
