#include <bits/stdc++.h>

using namespace std;


// ACC

const int N = 10010;  // limit for array size
int n, q, a, b;  // array size
int t[2 * N];

void build() {  // build the tree
    for (int i = n - 1; i > 0; --i) t[i] = min(t[i << 1], t[i << 1 | 1]);
}

int query(int l, int r) {  // sum on interval [l, r)
    int res = 10000;
    for (l += n, r += n; l < r; l >>= 1, r >>= 1) {
        if (l & 1) res = min(res, t[l++]);
        if (r & 1) res = min(res, t[--r]);
    }
    return res;
}

int main() {
    ios::sync_with_stdio(0);
    //cin.tie(0);
    cin >> n;
    for (int i = 0; i < n; i++) cin >> t[n + i];
    build();
    cin >> q;
    while (q--) {
        cin >> a >> b;
        if (a>b) swap(a, b);
        cout << query(a - 1, b) << "\n";
    }

    return 0;
}