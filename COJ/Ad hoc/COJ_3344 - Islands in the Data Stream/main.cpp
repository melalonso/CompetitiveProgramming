#include <bits/stdc++.h>

using namespace std;

// ACC

int main() {
    ios::sync_with_stdio(0);
    //cin.tie(0);
    int P, K, curr, prev;
    int res;
    cin >> P;
    while (P--) {
        res = 0;
        cin >> K;
        cin >> prev;
        for (int i = 1; i < 15; i++) {
            cin >> curr;
            if (curr < prev) res++;
            prev = curr;
        }
        cout << K << " " << res << "\n";
    }
    return 0;
}