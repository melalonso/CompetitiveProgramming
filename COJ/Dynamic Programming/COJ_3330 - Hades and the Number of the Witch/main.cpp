#include <bits/stdc++.h>
#define MOD 1000000007

using namespace std;

// ACC

int n, m;
string T, P;
int memo[100005][15];

int dp() {
    for (int i = 0; i < m; i++) memo[0][i] = 0;
    for (int i = 0; i < n; i++) memo[i][0] = 1;

    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            memo[i][j] = memo[i - 1][j];
            if (T[n - i] == P[m - j]) memo[i][j] = (memo[i][j] + memo[i - 1][j - 1])%MOD;
        }
    }
    return memo[n][m];
}

int main() {
    ios::sync_with_stdio(0);
    //cin.tie(0);
    cin >> m >> n;
    cin >> P;
    cin >> T;
    cout << dp() << "\n";
    return 0;
}