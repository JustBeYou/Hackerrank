#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include <unordered_map>
using namespace std;


int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */ 
    int n, v;
    cin >> v >> n;
    unordered_map<int, int> m;
    
    for (int i = 0, t; i < n; i++) {
        cin >> t;
        m[t] = i;
    }
    cout << m[v] << endl;
    
    return 0;
}
