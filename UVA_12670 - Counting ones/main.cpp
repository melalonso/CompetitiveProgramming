#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

int bin[66];
ll memo[66][2][66];

/*
 * ACCEPTED
 */

/*
ll dp(int pos, int smaller) {
    if (pos == -1)return 1;
    if (memo[pos][smaller] != -1) return memo[pos][smaller];
    ll res = 0;
    if (smaller) {
        res += 1+dp(pos - 1, smaller) + dp(pos - 1, smaller); // 1 or 0 in that position
    } else {
        if (bin[pos] == 0) {
            res += dp(pos - 1, 0); // to pass to next digit of n
        } else {
            res += dp(pos - 1, 1) +  1+dp(pos - 1, 0);
        }
    }
    return memo[pos][smaller] = res;
}
 */

ll dp(int pos, int smaller, int sum) {
    if (pos == -1)return sum;
    if (memo[pos][smaller][sum] != -1) return memo[pos][smaller][sum];
    ll res = 0;
    if (smaller) {
        res += dp(pos - 1, smaller, sum + 1) + dp(pos - 1, smaller, sum); // 1 or 0 in that position
    } else {
        if (bin[pos] == 0) {
            res += dp(pos - 1, 0, sum); // to pass to next digit of n
        } else {
            res += dp(pos - 1, 1, sum) + dp(pos - 1, 0, sum + 1);
        }
    }
    return memo[pos][smaller][sum] = res;
}


ll solve(ll n) {
    int cnt = 0;
    memset(memo, -1, sizeof memo);
    while (n) {
        bin[cnt++] = n % 2;
        n /= 2;
    }
    return dp(cnt - 1, 0, 0);
}

int main() {
    ios::sync_with_stdio(0);
    //cin.tie(0);
    ll a, b;
    while (cin >> a >> b) {
        cout << solve(b) - solve(a - 1) << "\n";
    }
    return 0;
}