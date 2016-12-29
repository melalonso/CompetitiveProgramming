#include <bits/stdc++.h>

#define MAXN 505
#define MAXH 45005

using namespace std;

// ACC

int memo[MAXH];
int weights[MAXN];
int h, n;

int dp(int i, int h) {
    if (i > n - 1) return 0;
    if (weights[i] > h) return dp(i + 1, h);
    if (memo[h] != -1) return memo[h];
    return memo[h] = max(weights[i] + dp(i + 1, h - weights[i]), dp(i + 1, h));
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> h >> n;
    for (int i = 0; i < n; i++) cin >> weights[i];
    memset(memo, -1, sizeof memo);
    cout << dp(0, h) << "\n";
    return 0;
}