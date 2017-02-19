#include <bits/stdc++.h>

#define MAXN 100002
#define CM 150000

// ACC

using namespace std;

const int N = MAXN;  // limit for array size
int n;  // array size
int t[2 * N];
int r[MAXN], l[MAXN];

void build() {  // build the tree
    for (int i = n - 1; i > 0; --i) t[i] = min(t[i << 1], t[i << 1 | 1]);
}

int query(int l, int r) {  // sum on interval [l, r)
    int res = INT32_MAX;
    for (l += n, r += n; l < r; l >>= 1, r >>= 1) {
        if (l & 1) res = min(res, t[l++]);
        if (r & 1) res = min(res, t[--r]);
    }
    return res;
}

void calcPeaks() {
    r[n - 1] = n;
    for (int i = n - 2; i >= 0; i--) {
        r[i] = i + 1;
        while (r[i] < n && t[n + i] >= t[n + r[i]])
            r[i] = r[r[i]];
    }

    l[0] = -1;
    for (int i = 1; i < n; i++) {
        l[i] = i - 1;
        while (l[i] >= 0 && t[n + i] >= t[n + l[i]])
            l[i] = l[l[i]];
    }
}

bool isPeak(int i) {
    return t[n + i - 1] < t[n + i] && t[n + i + 1] < t[n + i];
}

int main() {
    ios::sync_with_stdio(0);
    //cin.tie(0);
    int mini;
    vector<int> ultras;
    cin >> n;
    for (int i = 0; i < n; i++) cin >> t[n + i];
    build();
    calcPeaks();
    for (int i = 1; i < n - 1; i++) {
        if (isPeak(i)) {
            mini = t[i + n];
            if (l[i] != -1) mini = t[i + n] -  query(l[i], i);
            if (mini < CM) continue;

            mini = t[i + n];
            if (r[i] != n) mini = t[i + n] - query(i, r[i]);
            if (mini < CM) continue;

            ultras.push_back(i+1);
        }
    }
    cout << ultras[0];
    for (int i = 1; i < ultras.size(); i++) {
        cout << " " << ultras[i];
    }
    return 0;
}