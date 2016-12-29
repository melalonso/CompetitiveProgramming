#include <bits/stdc++.h>

using namespace std;

// ACC

int main() {
    ios::sync_with_stdio(0);
    //cin.tie(0);
    int cases, n, res, x;
    cin >> cases;
    while (cases--) {
        cin >> n;
        res = 0;
        for (int i = 1; i <= n; i++) {
            cin >> x;
            if (x != i) res++;
        }
        cout << res << "\n";
    }

    return 0;
}