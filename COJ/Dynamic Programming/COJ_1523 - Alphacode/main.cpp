#include <bits/stdc++.h>

#define MOD 987654321

using namespace std;


// ACC top down y bottom up

int memo[10010], n, num;
string w;

/*
int dp() {
    int num;
    memo[0] = memo[1] = 1;
    for (int i = 2; i <= n; i++) {
        num = ((w[i - 2] - '0') * 10) + (w[i - 1] - '0');
        if (w[i - 1] - '0') memo[i] = (memo[i] + memo[i - 1]) % MOD;
        if (num > 9 && num < 27) memo[i] = (memo[i] + memo[i - 2]) % MOD;
    }
    return memo[n];
}
*/

int dp(int i) {
    if (i <= 0) return 1;
    if (memo[i] != -1) return memo[i];

    int ans = 0;
    if (!(w[i] - '0')) {
        ans = dp(i - 2) % MOD;
    } else {
        ans = dp(i - 1) % MOD; // Take single digit
        num = ((w[i-1]-'0')*10) + w[i]-'0';
        if (num>9 && num<27) {
            ans = (ans + (dp(i - 2)))%MOD ; // Take two digits too
        }
    }
    return memo[i] = ans;
}

int main() {
    ios::sync_with_stdio(0);
    //cin.tie(0);
    while (cin >> w && w != "0") {
        n = (int) w.size();
        memset(memo, -1, sizeof memo);
        cout << dp(n-1) << "\n";
    }
    return 0;
}