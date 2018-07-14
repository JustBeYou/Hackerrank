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
    unsigned long long int a[5],max,min,sum=0;
    int i;
    scanf("%lld",&a[0]);
    max=a[0];min=a[0];sum=a[0]+sum;
    for(i=1;i<5;i++){
        scanf("%lld",&a[i]);
        if(max<a[i])
            max=a[i];
        if(min>a[i])
            min=a[i];
        sum=sum+a[i];
    }
    printf("%lld %lld",sum-max,sum-min);
    return 0;
}
