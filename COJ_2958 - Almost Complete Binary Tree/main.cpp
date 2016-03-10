#include <stdio.h>
#include <stdlib.h>
#include <math.h>

using namespace std;

/*
    ACCEPTED.
*/

int DP[3002][3002];
const int mod = 1000000007;

int C(int n, int k) {
    if ( k > n )        return 0;
    if ( !k || n == k ) return 1;
    if ( DP[n][k] )     return DP[n][k];
    DP[n][k] = (C(n-1, k)%mod + C(n-1, k-1)%mod)%mod;
    return DP[n][k];
}

int main()
{
    int T, N, h, total, k;
    scanf("%d", &T);
    while(T--){
        scanf("%d", &N);
        h = log2(N); // height of tree.
        total = pow(2, h);
        k = N - total + 1;
        printf("%d\n", C(total, k) - 1);
    }
    return 0;
}
