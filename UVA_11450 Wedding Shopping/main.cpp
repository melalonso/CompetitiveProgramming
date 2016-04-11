#include <iostream>
#include <bits/stdc++.h>
#define MAXN 22

using namespace std;

int garment[MAXN][MAXN];
int N, M, C, res;
int memo[202][MAXN];

/*
 * ACCEPTED
 */

int dp(int money, int i) {
    if (money<0) return -100000000;
    if (i == C) return M-money;
    if (memo[money][i] != -1) return memo[money][i];
    int ans = -1;
    for (int j=1; j<=garment[i][0]; j++) {
        ans = max(ans, dp(money - garment[i][j], i+1) );
    }
    return memo[money][i] = ans;
}


int main() {
    ios::sync_with_stdio(0);
    //cin.tie(0);
    cin >> N;
    while (N--) {
        cin >> M >> C;
        for (int i=0; i<C; i++) {
            cin >> garment[i][0];
            for (int j=1; j <= garment[i][0]; j++){
                cin >> garment[i][j];
            }
        }
        memset(memo, -1, sizeof memo);
        res = dp(M, 0);
        if (res == -1) cout << "no solution\n";
        else cout << res << "\n";
    }

    return 0;
}