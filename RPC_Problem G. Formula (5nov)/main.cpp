#include <bits/stdc++.h>

using namespace std;

int main() {
    ios::sync_with_stdio();
    int ax, ay, bx, by, cx, cy;
    double a, b, c;
    double calc_radius=0.0, area, radius;
    double a2, b2, c2;
    cin >> ax >> ay;
    cin >> bx >> by;
    cin >> cx >> cy;
    cin >> calc_radius;

    a = hypot(ax-bx, ay-by);
    b = hypot(ax-cx, ay-cy);
    c = hypot(cx-bx, cy-by);


    //area = abs( (ax*(by-cy) + bx*(cy-ay) + cx*(ay-by)) / 2);
    a2 = a*a;
    b2 = b*b;
    c2 = c*c;
    area = 0.25 * (sqrt(4*a2*b2 - ((a2+b2-c2)*(a2+b2-c2)) ));
    radius = area / ((a+b+c)/2);

    //double porcentage = 100-(100.0*radius/calc_radius);
    double porcentage = (radius/calc_radius-1)*100;
    //if (radius < calc_radius) porcentage *= -1.0;
    cout << porcentage << "\n";

    return 0;
}