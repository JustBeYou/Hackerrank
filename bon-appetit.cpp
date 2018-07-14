#include <map>
#include <set>
#include <list>
#include <cmath>
#include <ctime>
#include <deque>
#include <queue>
#include <stack>
#include <string>
#include <bitset>
#include <cstdio>
#include <limits>
#include <vector>
#include <climits>
#include <cstring>
#include <cstdlib>
#include <fstream>
#include <numeric>
#include <sstream>
#include <iostream>
#include <algorithm>
#include <unordered_map>

using namespace std;
int main() {
    int n, k;
    cin >> n >> k;
    
    int total = 0;
    vector<int> v(n + 2);
    for (int i = 0 ; i < n; i++) { cin >> v[i]; total += v[i];}
    int charged;
    cin >> charged;
    
    int shared_bill = total - v[k];
    if (shared_bill / 2 == charged) {
        cout << "Bon Appetit\n";
    } else {
        cout << charged - shared_bill / 2 << "\n";
    }
    
    return 0;
}
