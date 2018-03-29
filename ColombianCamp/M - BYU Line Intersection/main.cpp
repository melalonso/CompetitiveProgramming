#include <bits/stdc++.h>

using namespace std;

int main() {
    int x1, x2, x3;
    int y1, y2, y3;
    cin >> x1 >> y1;
    cin >> x2 >> y2;
    cin >> x3 >> y3;

    double c = x1*x2 + y1*y2;
    double m, b;
    m = -x2/y2;
    b = c/y2;

    

    return 0;
}