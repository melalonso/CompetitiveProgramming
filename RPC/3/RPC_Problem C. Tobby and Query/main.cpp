#include <bits/stdc++.h>

#define MAXN 100005
using namespace std;

int n, q, ai;
int l, r;

/*
    ACCEPTED
*/

int segment[2 * MAXN];

void modify(int p, int value) {  // set value at position p
    for (segment[p += n] = value; p > 1; p >>= 1)
        segment[p >> 1] = segment[p] | segment[p ^ 1];
}

int query(int l, int r) {  // sum on interval [l, r)
    int res = 0;
    for (l += n, r += n; l < r; l >>= 1, r >>= 1) {
        if (l & 1) res |= segment[l++];
        if (r & 1) res |= segment[--r];
    }
    return res;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    while (cin >> n) {
        memset(segment, 0, sizeof segment);
        for (int i = 0; i < n; i++) {
            cin >> ai;
            modify(i, 1 << ai);
        }
        cin >> q;
        while (q--) {
            cin >> l >> r;
            int res = query(l-1, r);
            cout << __builtin_popcount(res) << "\n";
        }
    }
    return 0;
}