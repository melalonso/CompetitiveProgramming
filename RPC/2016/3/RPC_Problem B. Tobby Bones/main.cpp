#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp> // Common file
#include <ext/pb_ds/tree_policy.hpp> // Including tree_order_statistics_node_update
#include <ext/pb_ds/detail/standard_policies.hpp>

#define MAXN 600000
#define INF 99999999
using namespace std;
using namespace __gnu_pbds;
typedef pair<int, int> ii;

/*
    ACCEPTED
*/

typedef tree<ii, null_type, less<ii>, rb_tree_tag, tree_order_statistics_node_update> bbt;
int n, m;

bbt segment[2 * MAXN];

int get(int pos, int s) {
    return segment[pos].order_of_key({s, INF});
}

int query(int l, int r, int s) {  // sum on interval [l, r)
    int res = 0;
    for (l += n, r += n; l < r; l >>= 1, r >>= 1) {
        if (l & 1) res += get(l++, s);
        if (r & 1) res += get(--r, s);
    }
    return res;
}

/*
 * Numeros: 1 <= N <= 600 000
 * Queries: 1<= M <= 2 000 000
 * Ni: 1 <= N <= 600 000
*/

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    int pos, B;
    int S, l, r;
    bool type;
    while (cin >> n >> m) {
        for (int i = 0; i < 2 * n; i++) segment[i].clear();
        for (int i = 0; i < m; i++) {
            cin >> type;
            if (type) {
                cin >> l >> r >> S;
                cout << query(l, r + 1, S) << "\n";
            } else {
                cin >> pos >> B;
                pos += n;
                ii node;
                if (segment[pos].size()) { // already has value
                    ii oldValue = *segment[pos].begin();
                    int posCp = pos;
                    segment[posCp].clear();
                    while (posCp >>= 1) {
                        segment[posCp].erase(oldValue);
                    }
                }
                node = {B, pos - n};
                segment[pos].insert(node);
                while (pos >>= 1) {
                    segment[pos].insert(node);
                }
            }
        }
    }
    return 0;
}