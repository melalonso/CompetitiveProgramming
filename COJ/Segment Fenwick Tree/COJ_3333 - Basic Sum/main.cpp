#include <bits/stdc++.h>

using namespace std;

// ACC

const int N = 100005;  // limit for array size
int n;  // array size
int t[2 * N];

void build() {  // build the tree
    for (int i = n - 1; i > 0; --i) t[i] = t[i << 1] + t[i << 1 | 1];
}

int query(int l, int r) {  // sum on interval [l, r)
    int res = 0;
    for (l += n, r += n; l < r; l >>= 1, r >>= 1) {
        if (l & 1) res += t[l++];
        if (r & 1) res += t[--r];
    }
    return res;
}

int main() {
    ios::sync_with_stdio(0);
    //cin.tie(0);
    int q;
    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> t[n + i];
    }
    build();
    cin >> q;
    int a, b;
    while (q--) {
        cin >> a >> b;
        cout << query(a - 1, b) << "\n";
    }
    return 0;
}