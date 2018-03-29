#include <bits/stdc++.h>
#include <utility>

#define forr(i, a, b) for(int i=(a); i<(b); i++)
#define forn(i, n) forr(i,0,n)
#define sz(c) ((int)c.size())
#define zero(v) memset(v, 0, sizeof(v))
#define dforn(i, n) for(int i=n-1; i>=0; i--)
#define MAXN 100005

using namespace std;

int n, q;
typedef long long ll;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n, s1, s2;
    int acc1, acc2;
    cin >> n;
    acc1 = acc2 = 0;
    int maxDiff = 0, winner = -1;
    forn(i, n) {
        cin >> s1 >> s2;
        acc1 += s1;
        acc2 += s2;
        //cout << abs(acc1 - acc2) << ".....\n";
        if (maxDiff < abs(acc1 - acc2)) {
            maxDiff = abs(acc1 - acc2);
            if (acc1 > acc2) winner = 1;
            else winner = 2;
        }
    }
    cout << winner << " " << maxDiff << "\n";
    return 0;
}