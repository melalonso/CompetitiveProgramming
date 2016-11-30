#include <bits/stdc++.h>

using namespace std;

// ACC

int main() {
    ios::sync_with_stdio(0);
    //cin.tie(0);
    int cases, n, p;
    string trick;
    cin >> cases;
    while (cases--) {
        cin >> n >> trick >> p;
        trick == "odd" ? cout << 2 * p << "\n" : cout << (2 * p) - 1 << "\n";
    }
    return 0;
}