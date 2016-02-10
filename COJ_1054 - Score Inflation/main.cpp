#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX 10002

using namespace std;

// 1 <= M, N, points, minutes <=10^4
int points[MAX];
int minutes[MAX];
int N, M;

/*
USES MUUUUCH MEMORY
int memo[MAX][MAX];

int DP(int M, int i){
    if (!M || i==N) return 0;
    if (memo[M][i] != -1) return memo[M][i];

    if (M-minutes[i] < 0)
        memo[M][i] = DP(M, i+1);
    else
        memo[M][i] = max(DP(M, i+1), points[i] + DP(M-minutes[i], i));
    return memo[M][i];
}
*/

/*
    ACCEPTED
*/

int dp[2][MAX];

int DP(){
    memset(dp[0], 0, sizeof(dp[0]));
    for(int i = 1; i <= N; i++) {
        int *cur = dp[i&1], *prev = dp[!(i&1)]; // Alternate rows
        for(int j = 0; j <= M; j++) {
            if (j-minutes[i-1] < 0)
                cur[j] = prev[j];
            else
                cur[j] = max(prev[j], points[i-1] + cur[j-minutes[i-1]] );

        }
    }
    return dp[N&1][M];
}

int main()
{
    int K;
    freopen("input","r",stdin);
    scanf("%d",&K);
    while(K--){
        scanf("%d %d", &M, &N);
        for (int i=0; i<N; i++){
            scanf("%d %d",&points[i], &minutes[i]);
        }
        printf("%d\n",DP());

    }
    return 0;
}
