#include <bits/stdc++.h>
#include <utility>

#define forr(i, a, b) for(int i=(a); i<(b); i++)
#define forn(i, n) forr(i,0,n)
#define sz(c) ((int)c.size())
#define zero(v) memset(v, 0, sizeof(v))
#define dforn(i, n) for(int i=n-1; i>=0; i--)

#define MAXV 105

using namespace std;

int n, m;
int parent[MAXV], ssize[MAXV];

int findSet(int x) {
    if (x == parent[x]) return x;
    return parent[x] = findSet(parent[x]);
}

bool unionSet(int x, int y) {
    x = findSet(x);
    y = findSet(y);
    if (x == y) return false;
    parent[x] = y;
    ssize[y] += ssize[x];
    return true;
}


int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int a, b;
    cin >> n >> m;
    forn(i, n) {
        parent[i] = i;
        ssize[i] = 1;
    }
    int ans = 0;
    forn(i, m) {
        cin >> a >> b;
        a--, b--;
        if (!unionSet(a, b)) {
            if (ssize[b] & 1) ans++;
        }
    }
    if ((n - ans) & 1) ans++;
    cout << ans << "\n";

    return 0;
}
