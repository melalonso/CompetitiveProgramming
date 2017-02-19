#include <bits/stdc++.h>
#define MOD 1000000000

using namespace std;

// ACC

typedef long long ll;

ll modPow(ll base, ll exp) {
    ll res = 1;
    while(exp) {
        if(exp & 1) res = (res * base)%MOD;
        base = (base*base)%MOD;
        exp >>= 1;
    }
    return res;
}

int main() {
    ios::sync_with_stdio(0);
    //cin.tie(0);
    int cases;
    ll a, b;
    cin >> cases;
    while (cases--) {
        cin >> a >> b;
        cout << modPow(a, b) << "\n";
    }
    return 0;
}