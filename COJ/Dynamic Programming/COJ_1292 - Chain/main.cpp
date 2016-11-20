#include <bits/stdc++.h>

#define MAXN 502
using namespace std;

int n, m;
string T, P;
int memo[MAXN][MAXN];

// ACC

int dp() {
    for (int i = 0; i < m; i++) memo[0][i] = 0;
    for (int i = 0; i < n; i++) memo[i][0] = 1;

    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            memo[i][j] = memo[i - 1][j];
            if (T[n - i] == P[m - j]) memo[i][j] += memo[i - 1][j - 1];
        }
    }
    return memo[n][m];
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    int cases;
    cin >> cases;
    while (cases--) {
        cin >> T >> P;
        n = T.size(), m = P.size();
        cout << dp() << "\n";
    }


    return 0;
}