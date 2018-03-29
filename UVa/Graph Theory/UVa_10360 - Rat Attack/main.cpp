#include <bits/stdc++.h>
#include <utility>

#define forr(i, a, b) for(int i=(a); i<(b); i++)
#define forn(i, n) forr(i,0,n)
#define sz(c) ((int)c.size())
#define zero(v) memset(v, 0, sizeof(v))
#define dforn(i, n) for(int i=n-1; i>=0; i--)
#define MAXN 1024

using namespace std;

// ACC

int killed[MAXN][MAXN], d, n;

void updateKills(int x, int y, int kills) {
    int startX = x - d;
    int startY = y - d;
    while (startX < 0) startX++;
    while (startY < 0) startY++;

    for (int i = startX; i <= x + d && i < MAXN; i++) {
        for (int j = startY; j <= y + d && j < MAXN; j++) {
            killed[i][j] += kills;
        }
    }
}

// max(abs(x2 − x1), abs(y2 − y1)) ≤ d
int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int cases;
    int x, y, kills;
    cin >> cases;
    while (cases--) {
        cin >> d >> n;
        forn(i, n) {
            cin >> x >> y >> kills;
            updateKills(x, y, kills);
        }

        int maxx = 0, bestX = -1, bestY = -1;
        forn(i, MAXN) {
            forn(j, MAXN) {
                if (killed[i][j] > maxx) {
                    maxx = killed[i][j];
                    bestX = i;
                    bestY = j;
                }
            }
        }

        cout << bestX << " " << bestY << " " << maxx << "\n";
        memset(killed, 0, sizeof killed);
    }
    return 0;
}