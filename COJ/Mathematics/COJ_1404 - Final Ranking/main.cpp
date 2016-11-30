#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MOD 1000003
#define MAXN 152

using namespace std;

/*
    ACCEPTED.
*/

// Bell Number
// S(n,k) = k*S(n-1,k)+S(n-1,k-1)

long long factorials[MAXN+1];
long long dp[MAXN+1][MAXN+1];

void init_factorials(){
    factorials[0] = factorials[1] = 1;
    for (int i = 2; i<MAXN; i++){
        factorials[i] = (i * factorials[i-1])%MOD;
    }
}

long long partitions(int n, int k){
  if (n == 0 || k == 0 || k > n) return 0;
  if (k == 1 || k == n) return 1;
  if (dp[n][k] != -1) return dp[n][k];
  dp[n][k] = ( (k*partitions(n-1, k))%MOD + partitions(n-1, k-1)%MOD) % MOD;
  return dp[n][k];
}

long long solve(int n){
    long long res = 0, p;
    for (int i=1; i<=n; i++){
        p = partitions(n, i);
        res = (res + (p*factorials[i])%MOD)%MOD;
    }
    return res;
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    int C, N;
    freopen("input", "r", stdin);
    memset(dp, -1, sizeof dp);
    init_factorials();
    cin >> C;
    while(C--){
        cin >> N;
        cout << solve(N) << "\n";
    }
    return 0;
}
