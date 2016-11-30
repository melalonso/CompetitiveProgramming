#include <bits/stdc++.h>

using namespace std;

// ACC

int main() {
    ios::sync_with_stdio(0);
    //cin.tie(0);
    int cases, n;
    cin >> cases;
    while (cases--) {
        cin >> n;
        string arr[n];
        for (int i = 0; i < n; i++) cin >> arr[i];

        for (int i = 0; i < n; i++) {
            i+1<n && arr[i + 1] > arr[i] ? cout << i + 2 : cout << -1;
            if (i < n - 1)cout << " ";
        }
        cout << "\n";
    }
    return 0;
}