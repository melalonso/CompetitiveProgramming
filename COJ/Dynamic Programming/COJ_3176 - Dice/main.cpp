#include <bits/stdc++.h>

using namespace std;

// ACC TopDown y BottomUp

long double memo[110][610];
int cases, n, m;

/*
long double dp(int n, int m){
    if (n == 0 && m == 0) return 1;
    if (n == 0 || m < 0) return 0;

    if (memo[n][m] > -0.5) return memo[n][m];

    long double ans = 0, x;
    for (int i=1; i<=6; i++){
        x = dp(n-1, m-i);
        ans += x/6;
    }
    return memo[n][m] = ans;
}
*/


long double dp() {
    memo[0][0] = 1;
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            for (int k = 1; k <= 6; k++) {
                if (j - k >= 0) memo[i][j] += (memo[i - 1][j - k] / 6);
            }
        }
    }
    return memo[n][m];
}

int main() {
    ios::sync_with_stdio(0);
    //cin.tie(0);
    cin >> cases;
    while (cases--) {
        cin >> n >> m;
        if (m > n * 6) cout << "0.00\n";
        else{
            memset(memo, 0.0, sizeof memo);
            cout << fixed << setprecision(2) << dp() << "\n";
        }
    }
    return 0;
}