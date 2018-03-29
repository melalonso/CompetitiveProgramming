#include <bits/stdc++.h>

#define forr(i, a, b) for(int i=(a); i<(b); i++)
#define forn(i, n) forr(i,0,n)
#define sz(c) ((int)c.size())
#define zero(v) memset(v, 0, sizeof(v))
#define dforn(i, n) for(int i=n-1; i>=0; i--)

// ACC

using namespace std;
int tracks[25];
int tapeSpace, numTracks, bestTotal, ans;


void BT(int i, int total, int bitmask) {
    if (total > tapeSpace) return;
    if (total > bestTotal){
        bestTotal = total;
        ans = bitmask;
    }
    if (i == numTracks) return;
    BT(i+1, total + tracks[i], bitmask | (1<<i));
    BT(i+1, total, bitmask);
}


int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    while (cin >> tapeSpace >> numTracks) {
        forn(i, numTracks) cin >> tracks[i];
        bestTotal = - 1;
        ans = -1;
        BT(0, 0, 0);
        forn(i, numTracks) {
            if (ans & (1 << i)) cout << tracks[i] << " ";
        }
        cout << "sum:" << bestTotal << "\n";
    }
    return 0;
}