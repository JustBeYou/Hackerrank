#include <fstream>
#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int main()
{
    //ifstream cin("coin.in");

    int n, m;
    cin >> n >> m;

    vector<int> coins(m);
    for (int i = 0; i < m; i++) {
        cin >> coins[i];
    }

    if (n == 0) {
        cout << 1 << endl;
    } else if (m == 0) {
        cout << 0 << endl;
    } else {
        vector< vector<long long> > combs(m + 1, vector<long long>(n + 1));

        for (int i = 0; i <= n; i++) combs[0][i] = 0;
        for (int i = 0; i <= m; i++) combs[i][0] = 1;

        for (int i = 1; i <= m; i++) {
            for (int j = 1; j <= n; j++) {
                if (coins[i - 1] > j) combs[i][j] = combs[i - 1][j];
                else combs[i][j] = combs[i][j - coins[i - 1]] + combs[i - 1][j];
            }
        }
        cout << combs[m][n] << endl;
    }
}

