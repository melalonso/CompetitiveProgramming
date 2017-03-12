#include <bits/stdc++.h>

#define MAXN 2005
using namespace std;

// ACC

int memo[MAXN];
int mapa[MAXN][MAXN];
int t, h, f;

int main() {
    ios::sync_with_stdio(0);
    //cin.tie(0);
    //freopen("input", "r", stdin);
    int cases, amt, pos;
    cin >> cases;
    while (cases--) {
        cin >> t >> h >> f;
        for (int i = 0; i < t; i++) {
            cin >> amt;
            while (amt--) {
                cin >> pos;
                mapa[i][pos]++;
            }
        }

        memset(memo, 0, sizeof memo);
        for (int i = h; i >= 0; i--) { // From top to bottom
            for (int j = 0; j < t; j++) { // For each tree
                mapa[j][i] += max(mapa[j][i + 1], (i+f)<=h ? memo[i+f] : 0);
                memo[i] = max(memo[i], mapa[j][i]);
            }
        }
        cout << memo[0] << "\n";
        memset(mapa, 0, sizeof mapa);
    }
    cin >> cases;
    return 0;
}