#include <bits/stdc++.h>
#define y second
using namespace std;

// ACC

typedef pair<int, int> ii;
int cases, x, yy, n;

vector<ii> v;

int CeilIndex(vector<int> &v, int l, int r, int key) {
    while (r-l > 1) {
        int m = l + (r-l)/2;
        if (v[m] > key) r = m;
        else l = m;
    }
    return r;
}

int LIS() {
    vector<int> tail(n);
    int length = 1;
    tail[0] = v[0].y;
    for (int i = 1; i < n; i++) {
        if (v[i].y < tail[0]) tail[0] = v[i].y;
        else if (v[i].y >= tail[length-1]) tail[length++] = v[i].y;
        else tail[CeilIndex(tail, -1, length-1, v[i].y)] = v[i].y;
    }
    return length;
}

int main() {
    ios::sync_with_stdio(0);
    //cin.tie(0);
    cin >> cases;
    while (cases--) {
        cin >> n;
        for (int i = 0; i < n; i++) {
            cin >> x >> yy;
            v.push_back({x, -yy});
        }
        sort(v.begin(), v.end());
        cout << LIS() << "\n";
        v.clear();
    }
    return 0;
}
