#include <bits/stdc++.h>

#define forr(i, a, b) for(int i=(a); i<(b); i++)
#define forn(i, n) forr(i,0,n)
#define sz(c) ((int)c.size())
#define zero(v) memset(v, 0, sizeof(v))
#define dforn(i, n) for(int i=n-1; i>=0; i--)
#define MAXN 100005
#define EPS 1e-7

// ACC

using namespace std;

int p, q, r, s, t, u;

double f(double x) {
    return p * exp(-x) + q * sin(x) + r * cos(x) + s * tan(x) + t * x * x + u;
}


int main() {
    ios::sync_with_stdio(false);
    //cin.tie(0);
    double high, low, mid;
    while (cin >> p >> q >> r >> s >> t >> u) {
        if (f(0) * f(1) > 0) cout << "No solution\n";
        else {
            high = 1, low = 0;
            while (low + EPS < high) {
                mid = (high + low) / 2;
                if (f(mid) * f(low) <= 0) high = mid;
                else low = mid;
            }
            cout << setprecision(4) << ((low + high) / 2) << "\n";
        }
    }

    return 0;
}