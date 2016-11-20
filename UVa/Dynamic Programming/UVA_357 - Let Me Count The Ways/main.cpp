#include <iostream>
#include <string.h>
#include <stdio.h>
#include <limits.h>

#define MAX 30000
using namespace std;

/*
    ACCEPTED
*/

int coins[] = {1, 5, 10, 25, 50}, money;
const int n = sizeof(coins)/sizeof(coins[0]);
long long memo[MAX][n];

long long DP(int m, int i){
    if (i == n || m < 0)  return 0;
    if (memo[m][i] != -1) return memo[m][i];
    if ( m == 0) return memo[0][i] = 1;

    long long res;
    res = DP(m-coins[i], i) + DP(m, i+1); // Add at least one coin of that type or not add anyone.
    return memo[m][i] = res;
}

void iter_DP(){
    long long res;
    for (int j=0; j<n; j++) memo[0][j] = 1;
    for (int i=1; i<=MAX; i++){
        for (int j=0; j<n; j++){
            res = 0;
            if (i-coins[j]>=0)
                res += memo[i-coins[j]][j];
            if (j>=1)
                res += memo[i][j-1];
            memo[i][j] = res;
        }
    }
}

int main()
{
    long long res;
    memset(memo, -1, sizeof memo);
    iter_DP();
    while(scanf("%d", &money)!=EOF){
        if (money<5){
            printf("There is only 1 way to produce %d cents change.\n", money);
        }else{
            printf("There are %llu ways to produce %d cents change.\n", memo[money][4], money);
        }
    }
    return 0;
}
