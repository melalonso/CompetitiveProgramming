#include <bits/stdc++.h>

using namespace std;

// ACC

int arr[1002];

int main() {
    ios::sync_with_stdio(0);
    //cin.tie(0);
    int cases, n, pos = -1;
    int processed, changes;
    cin >> cases;
    while (cases--) {
        cin >> n;
        for (int i = 0; i < n; i++) {
            cin >> arr[i];
            if (arr[i] == 1) pos = i;
        }

        changes = 0;
        processed = 1;
        if (arr[(pos + 1) % n] == n) pos = (pos + 1) % n;
        if (arr[(pos - 1 + n) % n] == 2) pos = (pos - 1 + n) % n;

        while (processed <= n) {
            if (arr[pos] != processed) changes++;
            pos = (pos+1)%n;
            processed++;
        }
        cout << changes << "\n";
    }
    return 0;
}