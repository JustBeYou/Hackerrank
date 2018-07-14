#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

#define MAX_N 100

char matrix[MAX_N][MAX_N];

void bubble_sort(char s[MAX_N], int n) {
    bool can_swap;
    
    do {
        can_swap = false;
        for (int i = 0; i < n - 1; i++) {
            if (s[i] > s[i + 1]) {
                swap(s[i], s[i + 1]);
                can_swap = true;
            }
        }    
    } while (can_swap);
}

int main() {
    int t, n;
    cin >> t;
    
    while (t--) {
        cin >> n;
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                cin >> matrix[i][j];
            }
            bubble_sort(matrix[i], n);
        }
        
        bool is_sorted = true;
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n - 1; j++) {
                if (matrix[j][i] > matrix[j + 1][i]) {
                    is_sorted = false;
                    break;
                }
            }
        }
        
        if (is_sorted) cout << "YES" << endl;
        else cout << "NO" << endl;
    }
    
    return 0;
}
