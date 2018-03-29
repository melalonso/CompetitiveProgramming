#include <bits/stdc++.h>

using namespace std;

const int N = 100005;
int n, q;
int t[2 * N];

void build() {
    for (int i = n - 1; i > 0; --i) t[i] = __gcd(t[i << 1], t[i << 1 | 1]);
}

int query(int l, int r) {
    int res = 0;
    for (l += n, r += n; l < r; l >>= 1, r >>= 1) {
        if (l & 1) res = __gcd(res, t[l++]);
        if (r & 1) res = __gcd(res, t[--r]);
    }
    return res;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int cases;
    cin >> cases;
    while (cases--) {
        cin >> n >> q;
        int x;
        for (int i = 0; i < n; ++i) {
            cin >> x;
            t[n + i] = x;
        }
        build();
        //printf("ESTE ES %d\n", query(0, 3));
        int l, r;
        for (int i = 0; i < q; i++) {
            cin >> l >> r;
            l--;
            r--;
            if (l == 0) {
                cout << query(r + 1, n) << "\n";
            } else if (r == n - 1) {
                cout << query(0, l) << "\n";
            } else {
                cout << __gcd(query(0, l), query(r + 1, n)) << "\n";
            }

        }
    }
    return 0;
}