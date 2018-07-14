#include <bits/stdc++.h>

using namespace std;

int migratoryBirds(int n, vector <int> ar) {
    int count[6] = {0};
    
    for (auto &elem: ar) {
        count[elem]++;
    }
    
    int sol = 1;
    int min_count = count[1];
    for (int i = 1; i < 6; i++) {
        if (count[i] > min_count) {
            min_count = count[i];
            sol = i;
        }
    }
    return sol;
}

int main() {
    int n;
    cin >> n;
    vector<int> ar(n);
    for(int ar_i = 0; ar_i < n; ar_i++){
       cin >> ar[ar_i];
    }
    int result = migratoryBirds(n, ar);
    cout << result << endl;
    return 0;
}
