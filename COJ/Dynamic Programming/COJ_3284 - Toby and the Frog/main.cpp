#include <bits/stdc++.h>

using namespace std;

long double memo[5010];
int cases, x;

// ACC

long double dp(int i) {
    if (i == x) return 1.0;
    if (memo[i] > -0.5) return memo[i];

    long double ans = 1;
    int limit = min(x - i, 10);
    for (int j = 1; j <= limit; j++) {
        ans += (dp(i + j) * (1.0 / limit));
    }

    return memo[i] = ans;
}

int main() {
    ios::sync_with_stdio(0);
    //cin.tie(0);
    cin >> cases;
    while (cases--) {
        cin >> x;
        memset(memo, -1.0, sizeof memo);
        cout << fixed << setprecision(10) << dp(0) - 1 << "\n";
    }
    return 0;
}