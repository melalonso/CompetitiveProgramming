#include <bits/stdc++.h>

using namespace std;
#define forr(i, a, b) for(int i=(a); i<(b); i++)
#define forn(i, n) forr(i,0,n)
#define sz(c) ((int)c.size())
#define zero(v) memset(v, 0, sizeof(v))
#define dforn(i, n) for(int i=n-1; i>=0; i--)

typedef long long ll;
const int MAXN = 1100;
vector<int> cows;
int N, C;

bool f(int x) {
    int allocated = 1;
    int first = cows[0];
    forr(i, 1, N) {
        if (cows[i] - first >= x) {
            allocated++;
            if (allocated == C) return true;
            first = cows[i];
        }
    }
    return false;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int cases, cow;
    cin >> cases;
    while (cases--) {
        cin >> N >> C;
        forn(i, N) {
            cin >> cow;
            cows.push_back(cow);
        }
        sort(cows.begin(), cows.end());

        int low = 0, high = cows[N - 1];
        while (high - low > 1) {
            int mid = low + (high - low) / 2;
            if (f(mid)) {
                low = mid;
            } else {
                high = mid;
            }
        }
        cout << low << "\n";
        cows.clear();
    }
    return 0;
}