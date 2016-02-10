#include <stdio.h>
#include <iostream>
#include <algorithm>
#include <string.h>
#include <climits>
#include <cmath>

#define MAX 12 // Max cities
using namespace std;

/*
    ACCEPTED
*/

int i, j, n;
int x[MAX];
int y[MAX];
int dist[MAX][MAX];
int memo[MAX][1 << MAX];

int DP(int currpos, int bitmask){
    if (bitmask == (1 << n) - 1)
        return dist[currpos][0];
    if (memo[currpos][bitmask] != -1)
        return memo[currpos][bitmask];

    int distance = INT_MAX;
    for (int nxtcty = 0; nxtcty < n; nxtcty++)
        if (nxtcty != currpos && !(bitmask & (1 << nxtcty)))
            distance = min(distance, dist[currpos][nxtcty] + DP(nxtcty, bitmask | (1 << nxtcty)));

    return memo[currpos][bitmask] = distance;
}

int main() {
    int cases, xsize, ysize;
    freopen("input","r",stdin);
    scanf("%d", &cases);
    while(cases--){
        scanf("%d %d", &xsize, &ysize);
        scanf("%d %d", &x[0], &y[0]);
        scanf("%d", &n);
        for (i = 1; i <= n; i++)
            scanf("%d %d", &x[i], &y[i]);

        for (i = 0; i <= n; i++)
            for (j = 0; j <= n; j++)
                dist[i][j] = abs(x[i]-x[j]) + abs(y[i]-y[j]);

        n++;
        memset(memo, -1, sizeof memo);
        printf("The shortest path has length %d\n", DP(0, 1));
    }
    return 0;
}
