#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

// ACC

long long memo[66][2][66];
int binary[66];

ll dp(int index, int smaller, int sum){
    if (index==-1) return sum;
    if (memo[index][smaller][sum] != -1) return memo[index][smaller][sum];
    ll res=0;
    if (smaller){
        res += dp(index-1, smaller, sum) + dp(index-1, smaller, sum+1);
    }else{
        if (binary[index]==0){
            res += dp(index-1, 0, sum);
        }else{
            res += dp(index-1, 1, sum)+dp(index-1, 0, sum+1);
        }
    }
    return memo[index][smaller][sum] = res;
}

ll solve(ll n){
    int cnt = 0;
    memset(memo, -1, sizeof memo);
    while (n) {
        binary[cnt++] = n % 2;
        n /= 2;
    }
    return dp(cnt-1,0,0);
}

int main() {
    ios::sync_with_stdio(0);
    //cin.tie(0);
    ll a, b;
    cin >> a >> b;
    cout << solve(b) - solve(a-1)<<"\n";
    return 0;
}