#include <bits/stdc++.h>

using namespace std;

// Not ACC Solution, need to fix bug

int main() {
    ios::sync_with_stdio(0);
    //cin.tie(0);
    int n, k, f;
    string state;
    int maxSave = -1, minBroken = INT_MAX;
    cin >> n >> k;
    for (int i = 0; i < n; i++) {
        cin >> f >> state;
        if (state == "SAFE") maxSave = max(maxSave, f);
        else minBroken = min(minBroken, f);
    }

    if (maxSave != -1) {
        cout << maxSave + 1 << " ";
    } else {
        cout << 2 << " ";
    }

    if (minBroken != INT_MAX) {
        if (minBroken - 1 == 1) cout << minBroken << "\n";
        else cout << minBroken - 1 << "\n";
    } else {
        cout << maxSave << "\n";
    }


    return 0;
}