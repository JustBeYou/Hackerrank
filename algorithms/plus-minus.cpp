#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <iomanip>
#include <algorithm>
using namespace std;


int main(){
    int n;
    cin >> n;
    vector<int> arr(n);
    
    int z = 0, p = 0;
    for(int arr_i = 0;arr_i < n;arr_i++){
       cin >> arr[arr_i];
        if (arr[arr_i] == 0) z++;
        else if (arr[arr_i] > 0) p++;
    }
    
    cout << setprecision(6) << (p / float(n)) << endl << ((n - p - z) / float(n)) << endl << (z / float(n)) << endl;
    
    return 0;
}
