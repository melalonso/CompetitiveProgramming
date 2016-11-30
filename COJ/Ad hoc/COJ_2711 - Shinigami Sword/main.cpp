#include <bits/stdc++.h>

using namespace std;

// ACC

typedef pair<int, int> ii;

int main() {
    ios::sync_with_stdio(0);
    //cin.tie(0);
    int n, x;
    cin >> n;
    vector<ii> shinigami(n);
    for (int i = 0; i < n; i++) {
        cin >> x;
        shinigami[i] = {x, i + 1};
    }
    sort(shinigami.begin(), shinigami.end(), greater<ii>());
    for (int i = 0; i < n; i++) cout << shinigami[i].second << "\n";
    return 0;
}