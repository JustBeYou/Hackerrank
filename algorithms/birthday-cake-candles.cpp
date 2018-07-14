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


int main(){
    int n;
    cin >> n;
    vector<int> height(n);
    for(int height_i = 0;height_i < n;height_i++){
       cin >> height[height_i];
    }
    
    int max_h = 0;
    int count = 0;
    for (int i = 0; i < n; i++) {
        if (height[i] > max_h) {
            count = 1;
            max_h = height[i];
        } else if (height[i] == max_h) {
            count++;
        }
    }
    
    cout << count << endl;
    
    return 0;
}
