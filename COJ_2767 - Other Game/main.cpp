#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <algorithm>
#include <vector>
#include <string>
#include <queue>
#include <limits.h>

#define MOD 1000000007

using namespace std;

/*
    ACCEPTED
*/

// 1 <= N <= 1000000
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    long long res, n;
    while(cin >> n) {
        res = ((n*(n+1)*(2*n+1))/6)%MOD;
        cout << res << "\n";
    }
    return 0;
}
