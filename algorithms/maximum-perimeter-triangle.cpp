#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;


int main() {
    int n;
    cin >> n;
    
    vector<int> sticks(n);
    for (int i = 0; i < n; i++) {
        cin >> sticks[i];
    }
    sort(sticks.begin(), sticks.end());
    
    long long max_sum = 0;
    long long sol_i = 0;
    for (long long i = n - 3, part_sum; i >= 0; i--) {
        if ((part_sum = sticks[i] + sticks[i + 1]) > sticks[i + 2]) {
            part_sum += sticks[i + 2];
            if (part_sum > max_sum) {
                max_sum = part_sum;
                sol_i = i;
            } 
        }
    }
    
    if (max_sum) {
        cout << sticks[sol_i] << " " << sticks[sol_i + 1] << " " << sticks[sol_i + 2] << endl;
    } else {
        cout << -1 << endl;
    }
    
    return 0;
}
