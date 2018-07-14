#include <bits/stdc++.h>

using namespace std;

int countingValleys(int n, string s) {
    int v = 0;     // # of valleys
        int lvl = 0;   // current level
        for(auto &c: s){
            if(c == 'U') ++lvl;
            if(c == 'D') --lvl;
            
            // if we just came UP to sea level
            if(lvl == 0 && c == 'U')
                ++v;
        }
    return v;
}

int main() {
    int n;
    cin >> n;
    string s;
    cin >> s;
    int result = countingValleys(n, s);
    cout << result << endl;
    return 0;
}
