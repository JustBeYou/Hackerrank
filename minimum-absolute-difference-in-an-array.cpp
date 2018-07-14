#include <bits/stdc++.h>
#include <cmath>

using namespace std;

int main(){
    int n;
    cin >> n;
    vector<int> a(n);
    for(int a_i = 0; a_i < n; a_i++){
       cin >> a[a_i];
    }
    sort(a.begin(), a.end());
    
    int min_diff = 1 << 17;
    for (int i = 0; i < n - 1; i++) {
        min_diff = min(min_diff, abs(a[i] - a[i + 1]));
    }
    cout << min_diff << endl;
    
    return 0;
}
