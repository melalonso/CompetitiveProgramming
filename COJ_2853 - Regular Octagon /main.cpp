#include <iostream>
#include <cmath>
#include <iomanip>

using namespace std;

/* NOT ACC */

int main() {
    ios::sync_with_stdio(0);
    //cin.tie(0);
    int n;
    double res = 0;
    while (cin >> n && n) {
        res = n * 2.0;
        res = res / ( 3.0 + (2.0 * sqrt(2.0)) );
        res = res * (1.0 + sqrt(2.0));
        printf("%.3f\n", res);
    }
    return 0;
}