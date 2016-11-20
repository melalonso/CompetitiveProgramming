#include <bits/stdc++.h>

using namespace std;

// ACC

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    double side, sqr3 =sqrt(3.0);
    while (cin >> side) {
        cout << fixed << setprecision(6) << sqr3*(side/4) << "\n";
    }
    return 0;
}