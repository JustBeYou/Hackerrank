#include <bits/stdc++.h>

using namespace std;

int main(){
    int n;
    cin >> n;
    vector<int> calories(n);
    for(int calories_i = 0; calories_i < n; calories_i++){
       cin >> calories[calories_i];
    }
    sort(calories.begin(), calories.end(), greater<int>());
    
    long long sol = calories[0];
    long long power_of_2 = 2;
    for (int i = 1; i < n; i++) {
        sol += power_of_2 * calories[i];
        power_of_2 <<= 1;
    }
    cout << sol << endl;
    
    return 0;
}
