#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

int x, y, d;

void extendedEuclid(int a, int b) {
    if (b == 0) {
        x = 1;
        y = 0;
        d = a;
        return;
    }
    extendedEuclid(b, a % b);
    int x1 = y;
    int y1 = x - (a / b) * y;
    x = x1;
    y = y1;
}


int main() {
    ios::sync_with_stdio(false);
    //cin.tie(0);
    long long a, b;
    while (cin >> a >> b) {
        extendedEuclid(a, b);
        cout << x << " " << y << " " << d << "\n";
    }
    return 0;
}