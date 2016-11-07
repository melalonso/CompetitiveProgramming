#include <iostream>
#include <string.h>
#include <limits>

#define INFN std::numeric_limits<int>::min()
using namespace std;

const int N = 1000002;  // limit for array size
int n;  // array size
int t[2 * N];

void build() {  // build the tree
    for (int i = n - 1; i > 0; --i) t[i] = max(t[i << 1], t[i << 1 | 1]);
}

int query(int l, int r) {
    int res = INFN;
    for (l += n, r += n; l < r; l >>= 1, r >>= 1) {
        if (l & 1) res = max(res, t[l++]);
        if (r & 1) res = max(res, t[--r]);
    }
    return res;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    int cases, k;
    cin >> cases;
    while (cases--) {
        cin >> n >> k;
        memset(t, 0, sizeof t);
        for (int i = 0; i < n; i++) cin >> t[n + i];
        build();

        int limit = n - k + 1;
        for (int j = 0; j < limit; j++) {
            cout << query(j, j + k);
            if (j + 1 < limit) cout << " ";
        }
        cout << "\n";
    }
    return 0;
}