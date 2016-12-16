#include <bits/stdc++.h>
#define MOD 1000000007

using namespace std;

// ACC

int memo[1000010];

int dp(int i){
    if (i<0) return 0;
    if (!i) return 1;
    if (memo[i] != -1) return memo[i];

    int ans = 0;
    ans = (dp(i-1) + dp(i-2))%MOD;

    return memo[i] = ans;
}

int main() {
    ios::sync_with_stdio(0);
    //cin.tie(0);
    int cases, n;
    cin >> cases;
    while(cases--){
        cin >> n;
        memset(memo, -1, sizeof memo);
        cout << dp(n) << "\n";
    }
    return 0;
}