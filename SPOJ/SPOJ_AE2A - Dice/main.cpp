#include <bits/stdc++.h>

#define MAXN 1000010

using namespace std;

typedef long long ll;
long long int memo[2][MAXN];

long long int dp(long int n, long int k) {
    if (memo[n][k] != -1) return memo[n][k];
    if (k < n || k > 6 * n) return 0;
    if (n == 1) memo[n][k] = 100 / 6;
    else {
        memo[n][k] = (dp(n - 1, k - 1) + dp(n - 1, k - 2)
                     + dp(n - 1, k - 3) + dp(n - 1, k - 4)
                     + dp(n - 1, k - 5) + dp(n - 1, k - 6)) / 6;
    }
    return memo[n][k];
}

ll DP(int N, int K) {
    memset(memo, 0, sizeof memo);
    for (int i = 1; i <= 6; i++) memo[1][i] = 100 / 6;
    ll *curr, *prev;
    for (int i = 2; i <= N; i++) {
        curr = memo[!(i & 1)];
        prev = memo[(i & 1)];
        for (int j = 2; j <= K; j++) {
            for (int k = 1; k <= 6; k++) if (j - k >= 0)
                curr[j] += prev[j - k];
        }
    }
    return memo[!(N&1)][K];
}


int main() {
    ios::sync_with_stdio(0);
    //cin.tie(0);
    int t, n, k;
    cin >> t;
    while (t--) {
        cin >> n >> k;
        memset(memo, -1, sizeof memo);
        cout << dp(n, k) << "\n";
    }
    return 0;
}