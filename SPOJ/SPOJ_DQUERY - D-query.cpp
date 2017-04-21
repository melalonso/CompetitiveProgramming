#include <bits/stdc++.h>

#define MAXSIZE 30002
#define MAXN 1000002
#define MAXQ 200002
using namespace std;

int n, sq, t;
struct Qu {
    int l, r, id;
} qs[MAXQ];

int ans[MAXQ], curans;
int freq[MAXN], arr[MAXSIZE];

bool bymos(const Qu &a, const Qu &b) {
    if (a.l / sq != b.l / sq) return a.l < b.l;
    return (a.l / sq) & 1 ? a.r < b.r : a.r > b.r;
}

void add(int x) {
    freq[arr[x]]++;
    if (freq[arr[x]] == 1) curans++;
}

void rem(int x) {
    freq[arr[x]]--;
    if (!freq[arr[x]]) curans--;
}

void mos() {
    sq = sqrt(n);
    sort(qs, qs + t, bymos);
    int cl = 0, cr = 0;
    curans = 0;
    for (int i = 0; i < t; i++) {
        Qu &q = qs[i];
        while (cl > q.l) add(--cl);
        while (cr < q.r) add(cr++);
        while (cl < q.l) rem(cl++);
        while (cr > q.r) rem(--cr);
        ans[q.id] = curans;
    }
}

int main() {
    ios::sync_with_stdio(0);

    freopen("output", "w", stdout);
    //cin.tie(0);
    int left, right;

    cin >> n;
    for (int i = 0; i < n; i++) cin >> arr[i];

    cin >> t;
    for (int i = 0; i < t; i++) {
        cin >> left >> right;
        qs[i].l = left-1;
        qs[i].r = right;
        qs[i].id = i;
    }

    mos();

    for (int i = 0; i < t; i++) {
        cout << ans[i] << "\n";
    }

    return 0;
}
