#include <bits/stdc++.h>

using namespace std;

// ACC

typedef long long ll;
int n;
string s;
const string ss = "COW";
long long memo[100002][3];

ll dp(int i, int j) {
    if (i == n && j == 3 || j == 3) return 1;
    if (i == n) return 0;
    if (memo[i][j] != -1) return memo[i][j];
    ll ans = dp(i + 1, j);
    if (s[i] == ss[j]) ans += dp(i + 1, j + 1);
    return memo[i][j] = ans;
}

int main() {
    ios::sync_with_stdio(0);
    //cin.tie(0);
    cin >> n;
    cin >> s;
    memset(memo, -1, sizeof memo);
    cout << dp(0, 0) << "\n";
    return 0;
}