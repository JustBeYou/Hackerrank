#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

int n, k;
int combs = 0;
int limit;

void calc_combs(int i, int sum)
{
    //cout << i << " " << sum << endl;
    if (sum > n) return ;
    if (sum == n) combs++;
    
    for (int j = i + 1; j <= limit; j++)
        calc_combs(j, sum + pow(j, k));
}

int main() {
    cin >> n >> k;
    
    limit = int(pow(n, 1.00 / k)) + 1;
    for (int i = 1; i <= limit; i++) 
        calc_combs(i, pow(i, k));
    cout << combs << endl;
    
    return 0;
}
