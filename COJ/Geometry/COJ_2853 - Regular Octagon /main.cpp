#include <iostream>
#include <cmath>
#include <iomanip>

using namespace std;

// ACC

int main() {
    ios::sync_with_stdio(0);
    //cin.tie(0);
    int n;
    double res = 0, side, sqrt2 = sqrt(2);
    while (cin >> n && n) {
        side = n /(1.0+sqrt2);
        res = (2+2*sqrt2)*side*side;
        cout << fixed << setprecision(3) << res << "\n";
    }
    return 0;
}