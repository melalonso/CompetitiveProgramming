#include <bits/stdc++.h>
#define MOD 998244353

using namespace std;

typedef unsigned long long ll;

// ACCEPTED

ll modExp(ll base, int exp){
    ll r = 1;
    base %= MOD;
    while (exp){
        if (exp&1) r=(r*base) % MOD;
        base=(base * base) % MOD;
        exp>>=1;
    }
    return r;
}

// i^3 - i
int main() {
    ios::sync_with_stdio(0);
    //cin.tie(0);
    ll n, res;
    ll inv2 = 499122177; // modExp(2, MOD-2);
    while (cin >> n) {
        n %= MOD;
        res = ((n * (n+1))%MOD * inv2)%MOD;
        res = (((res * res)%MOD - res) + MOD)%MOD;
        cout << res << "\n";
    }
    return 0;
}