#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX 52

using namespace std;

/*
    DP
    ACCEPTED.
*/

long long memo[MAX][MAX][MAX];

int combination(int n,int k){
  int c=1;
  for (int i = 0; i < k; ++i){
    c = c * (n - i);
    c = c / (i + 1);
  }
  return c;
}



long long DP(int n, int k, int m){
    if (!k && !n) return 1;
    if (!k || !n) return 0;
    if (memo[n][k][m] != -1) return memo[n][k][m];
    long long ans = 0;
    for (int i=1; i<=m; i++){
        if ((n-i)>=0)
            ans += DP(n-i, k-1, m);
    }
    return memo[n][k][m] = ans;
}

int main()
{
    int n, k, m;
    freopen("input", "r", stdin);
    while(scanf("%d %d %d", &n, &k, &m)!=EOF){
        memset(memo, -1, sizeof memo);
        printf("%lld\n", DP(n, k, m));
    }
    return 0;
}
