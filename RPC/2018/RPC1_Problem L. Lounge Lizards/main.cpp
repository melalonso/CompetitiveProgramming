#include <bits/stdc++.h>

using namespace std;

struct vec {
    int x, y;

    int len() { return __gcd(abs(x), abs(y)); }

    vec normalized() {
        int gcd = max(len(), 1);
        return {x / gcd, y / gcd};
    }

    bool operator<(vec const &a) const {
        return x != a.x ? x < a.x : y < a.y;
    }
};

vec v;
int n, h, tx, ty;
typedef pair<int, int> ii;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cin >> tx >> ty >> n;
    map<vec, vector<ii>> groups;
    for (int i = 0; i < n; i++) {
        cin >> v.x >> v.y >> h;
        v.x -= tx;
        v.y -= ty;
        groups[v.normalized()].emplace_back(v.len(), h);
    }
    int ans = 0;
    for (auto &item : groups) {
        vector<int> best;
        sort(item.second.begin(), item.second.end());
        for (auto &v: item.second) {
            int h = v.second;
            auto it = lower_bound(best.begin(), best.end(), h);
            if (it == best.end()) best.push_back(h);
            else *it = h;
        }
        ans += best.size();
    }
    cout << ans << "\n";
    return 0;
}