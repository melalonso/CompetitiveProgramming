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
ll arr[MAXN], tree[4 * MAXN], lazy[4 * MAXN];

void build(int node, int start, int end) {
    if (start == end) tree[node] = arr[node];
    else {
        int mid = (start + end) / 2;
        build(2 * node, start, mid);
        build(2 * node + 1, mid + 1, end);
        tree[node] = tree[2 * node] + tree[2 * node + 1];
    }
}

void update(int node, int start, int end, int idx, int val) {
    if (start == end) {
        //arr[idx] += val;
        tree[node] += val;
    } else {
        int mid = (start + end) / 2;
        if (start <= idx && idx <= mid) {
            update(2 * node, start, mid, idx, val);
        } else {
            update(2 * node + 1, mid + 1, end, idx, val);
        }
        tree[node] = tree[2 * node] + tree[2 * node + 1];
    }
}

void updateRange(int node, int start, int end, int l, int r, ll val) {
    if (lazy[node] != 0) { // needs to be updated
        tree[node] += (end - start + 1) * lazy[node];
        if (start != end) {
            lazy[node * 2] += lazy[node];
            lazy[node * 2 + 1] += lazy[node];
        }
        lazy[node] = 0;
    }
    if (start > end || start > r || end < l) return;
    if (l <= start && end <= r) {
        tree[node] += (end - start + 1) * val;
        if (start != end) {
            lazy[node * 2] += val;
            lazy[node * 2 + 1] += val;
        }
        return;
    }
    int mid = (start + end) / 2;
    updateRange(node * 2, start, mid, l, r, val);
    updateRange(node * 2 + 1, mid + 1, end, l, r, val);
    tree[node] = tree[node * 2] + tree[node * 2 + 1];
}

ll query(int node, int start, int end, int l, int r) {
    if (l > end || r < start) return 0;
    if (l <= start && end <= r) return tree[node];
    int mid = (start + end) / 2;
    ll p1 = query(2 * node, start, mid, l, r);
    ll p2 = query(2 * node + 1, mid + 1, end, l, r);
    return p1 + p2;
}

ll queryRange(int node, int start, int end, int l, int r) {
    if (start > end || l > end || r < start) return 0;
    if (lazy[node] != 0) {
        tree[node] += (end - start + 1) * lazy[node];
        if (start != end) {
            lazy[node * 2] += lazy[node];
            lazy[node * 2 + 1] += lazy[node];
        }
        lazy[node] = 0;
    }
    if (l <= start && end <= r) return tree[node];
    int mid = (start + end) / 2;
    ll p1 = queryRange(2 * node, start, mid, l, r);
    ll p2 = queryRange(2 * node + 1, mid + 1, end, l, r);
    return (p1 + p2);
}


int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
/*    freopen("input", "r", stdin);
    freopen("output", "w", stdout);*/
    int cases, type, a, b;
    ll val;
    cin >> cases;
    forr(i, 1, cases+1) {
        cin >> n >> q;
        forn(i, q) {
            cin >> type >> a >> b;
            a--;
            b--;
            if (!type) {
                cin >> val;
                updateRange(1, 0, n - 1, a, b, val);
            } else {
                cout << queryRange(1, 0, n - 1, a, b) << "\n";
            }

        }
        memset(lazy, 0, sizeof lazy);
        memset(tree, 0, sizeof tree);
    }
    return 0;
}