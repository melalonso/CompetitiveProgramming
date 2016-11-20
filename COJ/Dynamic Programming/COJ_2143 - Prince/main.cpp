#include <bits/stdc++.h>

using namespace std;

// ACC

int weights[255], coins[255];
int memo[252][1002];
int cases, n, m, res = 0;

int knapsack(int i, int w) {
    if (i == n) return 0;
    if (memo[i][w] != -1) return memo[i][w];
    int ans = 0;
    if (w >= weights[i])
        ans = max(coins[i] + knapsack(i + 1, w - weights[i]), knapsack(i + 1, w));
    else
        ans = knapsack(i + 1, w);
    return memo[i][w] = ans;
}

int main() {
    ios::sync_with_stdio(0);
    //cin.tie(0);
    cin >> cases;
    while (cases--) {
        cin >> n >> m;
        for (int i = 0; i < n; i++) {
            cin >> weights[i] >> coins[i];
        }
        memset(memo, -1, sizeof memo);
        res += knapsack(0, m);
    }
    cout << res << "\n";
    return 0;
}