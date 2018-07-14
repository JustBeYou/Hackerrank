#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;


int main(){
    int n;
    cin >> n;
    vector<int> arr(n);
    for(int arr_i = 0;arr_i < n;arr_i++){
       cin >> arr[arr_i];
    }
    
    long long s = 0;
    for (int i = 0 ; i < n ; i ++) {
        s += arr[i];
    }
    
    
    cout << s << endl;
    return 0;
}
