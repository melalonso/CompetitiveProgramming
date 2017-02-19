#include <bits/stdc++.h>
#define MAXN 100002
#define INF 1000000000

using namespace std;

// ACC, could be solved greedy

int coin[4] = {1, 3, 5, 6};
int memo[4][MAXN];

int dp(int i, int money) {
    if(money == 0) return 0;
    if(money < 0) return INF;
    if(i < 0 && money > 0) return INF;
    if(memo[i][money] != -1) return memo[i][money];

    memo[i][money] = min(dp(i - 1, money), dp(i, money - coin[i]) + 1);

    return memo[i][money];
}

int main() {
    ios::sync_with_stdio(0);
    //cin.tie(0);
    int cases, n;
    cin >> cases;
    memset(memo, -1, sizeof memo);
    for (int i=1; i<=cases; i++){
        cin >> n;
        cout << "Case "<<i<<": "<< dp(3, n) << "\n";
    }
    return 0;
}