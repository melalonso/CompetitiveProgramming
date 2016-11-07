#include <iostream>
#include <stdio.h>
#include <string.h>

#define MAXN 205
using namespace std;

/*
    ACCEPTED

*/

int N, Q, D, M, *nums;
int memo[MAXN][25][15];

int DP(int i, int sum, int m){
    if (!m && !sum) return 1;
    if (!m && sum || i==N) return 0;
    if (memo[i][sum][m] != -1) return memo[i][sum][m];
    // (a-b)%m = ((a%m-b%m)+m)%m
    memo[i][sum][m] = DP(i+1, ((sum%D + nums[i]%D)+D)%D, m-1) + DP(i+1, sum, m);
    return memo[i][sum][m];
}

int main()
{
    int idx = 1, res;
    freopen("input","r",stdin);
    while (scanf("%d %d",&N, &Q), N || Q){
        nums = new int[N];
        for (int i=0; i<N; i++) scanf("%d",&nums[i]);

        printf("SET %d:\n",idx);
        for (int i=1; i<=Q; i++){
            scanf("%d %d",&D, &M);
            memset(memo, -1, sizeof(memo));
            res = DP(0, 0, M); // Curr idx, sum, M left.
            printf("QUERY %d: %d\n", i, res);
        }
        idx++;
    }

    return 0;
}
