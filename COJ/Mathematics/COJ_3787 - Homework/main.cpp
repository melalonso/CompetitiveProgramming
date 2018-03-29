#include <bits/stdc++.h>

using namespace std;

// ACC

bool isInteger(double n) {
    return floor(n) == n;
}

int main() {
    ios::sync_with_stdio(false);
    //cin.tie(0);
    int cases, n;
    cin >> cases;
    while (cases--) {
        cin >> n;
        double res = (-1 + sqrt(1 + 8 * n)) / 2;
        if (isInteger(res)) cout << (int) res - 1 << "\n";
        else cout << "No solution\n";
    }
    return 0;
}