#include <bits/stdc++.h>

using namespace std;
#define forr(i, a, b) for(int i=(a); i<(b); i++)
#define forn(i, n) forr(i,0,n)
#define sz(c) ((int)c.size())
#define zero(v) memset(v, 0, sizeof(v))
#define dforn(i, n) for(int i=n-1; i>=0; i--)

typedef long long ll;
const int MAXN = 10005;
int prices[MAXN];
set<int> books;
int N, C, b;

int main() {
    ios::sync_with_stdio(false);
    //cin.tie(0);
    while (cin >> N) {
        forn(i, N) {
            cin >> b;
            prices[i] = b;
            books.insert(b);
        }
        cin >> C;
        int sol1, sol2;
        int difference = INT_MAX;
        forn(i, N) {
            if (books.find(C - prices[i]) != books.end()) {
                cout << "Encontre " << prices[i] << "\n";
                int maxx = max(prices[i], C - prices[i]);
                int minn = min(prices[i], C - prices[i]);
                if (maxx - minn < difference) {
                    sol1 = minn;
                    sol2 = maxx;
                }
            }
        }

        cout << "Peter should buy books whose prices are " << sol1 << " and " << sol2 << ".\n";

        string s;
        getline(cin, s);
        books.clear();

    }
    return 0;
}