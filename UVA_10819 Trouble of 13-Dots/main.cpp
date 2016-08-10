#include <iostream>
#include <bits/stdc++.h>

#define oo -1000000
using namespace std;

typedef pair<int,int> pii;

/*
 * ACCEPTED.
 */

pii items[111];
int memo[10222][111], m, n;


int dp(int money, int i) {
    if ( money > m &&  m <= 1800 ) return oo;
    if ( money > m &&  money-m > 200 ) return oo;
    if (i == n) {
        if (money > m && money <= 2000) return oo;
        return 0;
    }
    if (memo[money][i] != -1) return memo[money][i];
    int ans = 0;
    ans = max(items[i].second + dp(money + items[i].first, i+1), dp(money, i+1));
    return memo[money][i] = ans;
}

int main() {
    ios::sync_with_stdio(0);
    //cin.tie(0);
    while(cin >> m >> n){
        for (int i=0; i<n; i++){
            cin >> items[i].first >> items[i].second;
        }
        memset(memo, -1, sizeof memo);
        int res = dp(0, 0);
        cout << res << "\n";
    }
    return 0;
}