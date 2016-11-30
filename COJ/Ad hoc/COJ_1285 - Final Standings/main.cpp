#include <bits/stdc++.h>

using namespace std;
typedef pair<int, int> ii;

// ACC

bool mygreater(ii a, ii b) {
    return a.second > b.second;
}

int main() {
    ios::sync_with_stdio(0);
    //cin.tie(0);
    int n, id, m;
    vector<ii> scores;
    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> id >> m;
        scores.push_back({id, m});
    }

    stable_sort(scores.begin(), scores.end(), mygreater);
    for (int i = 0; i < n; i++) {
        cout << scores[i].first << " " << scores[i].second << "\n";
    }
    return 0;
}