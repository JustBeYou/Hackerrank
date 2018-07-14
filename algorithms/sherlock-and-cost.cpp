#include <bits/stdc++.h>

using namespace std;

int cost(vector <int> arr) {
    int high = 0, low = 0;
    int next_high, next_low;
    
    for (int i = 1; i < arr.size(); i++) {
        next_low = max(low, high + abs(arr[i - 1] - 1));
        next_high = max(low + abs(arr[i] - 1), high + abs(arr[i] - arr[i - 1]));
        
        low = next_low;
        high = next_high;
    }
    
    return max(low, high);
}

int main() {
    int t;
    cin >> t;
    for(int a0 = 0; a0 < t; a0++){
        int n;
        cin >> n;
        vector<int> arr(n);
        for(int arr_i = 0; arr_i < n; arr_i++){
           cin >> arr[arr_i];
        }
        int result = cost(arr);
        cout << result << endl;
    }
    return 0;
}
