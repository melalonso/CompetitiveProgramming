#include <bits/stdc++.h>

#define forr(i, a, b) for(int i=(a); i<(b); i++)
#define forn(i, n) forr(i,0,n)
#define sz(c) ((int)c.size())
#define zero(v) memset(v, 0, sizeof(v))
#define dforn(i, n) for(int i=n-1; i>=0; i--)

#define MAXV 105

using namespace std;

int n, k, a, b;

void swapBit(int i, int j) {
    int ft = n & (1 << i);
    int sc = n & (1 << j);
    if (ft != sc) {
        if (ft) {
            n = n | (1 << i);
        } else {
            n = n | (1 << j);
        }
    }
}


int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cin >> n >> k;
    int maxx = 0, minn = INT_MAX;
    forn(i, k) {
        cin >> a >> b;
        swapBit(a, b);
        maxx = max(maxx, n);
        minn = min(minn, n);
    }
    cin >> a >> b;
    cout << n << " " << maxx << " " << minn << "\n";
    return 0;
}
