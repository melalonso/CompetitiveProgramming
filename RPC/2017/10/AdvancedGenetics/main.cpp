#include <bits/stdc++.h>

using namespace std;
#define forr(i, a, b) for(int i=(a); i<(b); i++)
#define forn(i, n) forr(i,0,n)
#define sz(c) ((int)c.size())
#define zero(v) memset(v, 0, sizeof(v))
#define dforn(i, n) for(int i=n-1; i>=0; i--)

typedef long long ll;
const int MAXN = 1100;

ll rkPot[MAXN], rk_p = 257, rk_M = 1000000007;
ll suffix[MAXN], preffix[MAXN];
ll memo[MAXN];

void initRK() {
    ll p = 1;
    for (int i = 0; i < MAXN; i++, p = (p * rk_p) % rk_M) {
        rkPot[i] = p;
    }
}

ll calcHashRK(int start, int offset, string s) {
    ll r = 0;
    forr(i, start, start + offset) {
        r = (r + rkPot[i - start] * s[i]) % rk_M;
    }
    return r;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int cases, n, k;
    string a, b;
    initRK();
    cin >> cases;
    string startStr;
    while (cases--) {
        cin >> n >> k;
        cin >> startStr;
        sort(startStr.end() - k, startStr.end());
        preffix[0] = -1;
        suffix[0] = calcHashRK(sz(startStr) - k, k, startStr);
        forn(i, n) {
            cin >> a;
            b = a;
            sort(a.begin(), a.begin() + k);
            sort(b.end() - k, b.end());
            preffix[i + 1] = calcHashRK(0, k, a);
            suffix[i + 1] = calcHashRK(sz(b) - k, k, b);
        }
        zero(memo);

        dforn(i, n + 1) {
            forr(j, i + 1, n + 1) {
                if (suffix[i] == preffix[j]) {
                    memo[i] = max(memo[i], memo[j] + 1);
                }
            }
        }

        cout << memo[0] << "\n";
    }
    return 0;
}