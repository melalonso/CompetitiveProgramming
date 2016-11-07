#include <iostream>
#include <stdio.h>

#define mod 1000000

using namespace std;

int DP[201][102];

/*
    ACCEPTED
    https://en.wikipedia.org/wiki/Stars_and_bars_%28combinatorics%29
*/

int C(int n, int k) {
    if ( k > n )        return 0;
    if ( !k || n == k ) return 1;
    if ( DP[n][k] )     return DP[n][k];
    DP[n][k] = (C(n-1, k)%mod + C(n-1, k-1)%mod)%mod;
    return DP[n][k];
}

int main()
{
    int N, K;
    while(scanf("%d %d",&N, &K), N|K){
        cout << C(N+K-1, N) << endl;
    }
    return 0;
}
