#include <bits/stdc++.h>

using namespace std;

bool cmp(string i,string j) 
{ 
    int n=i.length();
    int m=j.length();
    if(n==m)
        return (i<j);
    
    return n<m;   
}

vector <string> bigSorting(vector <string> arr) {
    sort(arr.begin(), arr.end(), cmp);
    
    return arr;
}

int main() {
    int n;
    cin >> n;
    vector<string> arr(n);
    for(int arr_i = 0; arr_i < n; arr_i++){
       cin >> arr[arr_i];
    }
    vector <string> result = bigSorting(arr);
    for (ssize_t i = 0; i < result.size(); i++) {
        cout << result[i] << (i != result.size() - 1 ? "\n" : "");
    }
    cout << endl;


    return 0;
}
