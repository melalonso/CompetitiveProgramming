#include <bits/stdc++.h>

#define MAXN 1000000
#define MOD 1000000007

using namespace std;
typedef long long ll;

ll fact[MAXN];

void calcfactorial() {
    fact[0] = fact[1] = 1;
    for (int i = 2; i <= MAXN; i++) {
        fact[i] = (fact[i - 1] * i) % MOD;
    }
}

ll modExp(ll base, ll exp, ll M = MOD) {
    ll r = 1;
    base %= M;
    while (exp) {
        if (exp & 1) r = (r * base) % M;
        base = (base * base) % M;
        exp >>= 1;
    }
    return r;
}

// n! / k! (n-k)!
int main() {
    ios::sync_with_stdio(0);
    //cin.tie(0);
    int n, k;
    ll invMod, res, binomial, den;
    calcfactorial();
    while (cin >> n >> k) {
        res = ((modExp(2, n, MOD - 1) - n) + MOD) % MOD;
        res = modExp(2, res);

        den = (fact[k] * fact[n - k]) % MOD;
        invMod = modExp(den, MOD - 2);
        binomial = (fact[n] * invMod) % MOD;

        cout << (res * binomial) % MOD << "\n";
    }
    return 0;
}