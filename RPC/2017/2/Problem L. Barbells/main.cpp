#include <bits/stdc++.h>

using namespace std;

// ACC

typedef long long ll;
typedef pair<ll, int> ii;

int n, m;
ll acc = 0;
ll barbells[20], plates[20];
set<ll> answer;

void solve() {
    vector<ii> sums;
    for (int bitmask = 1; bitmask < (1 << m); bitmask++) {
        ll w = 0;
        for (int i = 0; i < m; i++) w += ((bitmask & (1<<i)) ? plates[i] : 0);
        if (w <= acc/2){
            sums.push_back({w, bitmask});
        }
    }

    sort(sums.begin(), sums.end());

    vector<ll> validSums;
    for (int i = 0; i < sums.size(); i++) {
        int bm = sums[i].second;
        ii lookFor = {sums[i].first, 0};

        int idx = lower_bound(sums.begin(), sums.end(), lookFor) - sums.begin();

        for (int j = idx; j < sums.size() && lookFor.first == sums[j].first; j++) {
            if (!(bm & sums[j].second)) {
                validSums.push_back(lookFor.first);
                i = (lower_bound(sums.begin(), sums.end(), make_pair(lookFor.first + 1, -1)) - sums.begin());
                break;
            }
        }
    }

    for (int i = 0; i < validSums.size(); i++) {
        for (int j = 0; j < n; j++) {
            answer.insert(barbells[j] + (validSums[i]*2));
        }
    }

    for (auto i : answer) {
        cout << i << "\n";
    }
}





int main() {
    ios::sync_with_stdio(0);
    //cin.tie(0);
    cin >> n >> m;
    for (int i = 0; i < n; i++) {
        cin >> barbells[i];
        answer.insert(barbells[i]);
    }
    for (int i = 0; i < m; i++) {
        cin >> plates[i];
        acc += plates[i];
    }

    solve();

    return 0;
}