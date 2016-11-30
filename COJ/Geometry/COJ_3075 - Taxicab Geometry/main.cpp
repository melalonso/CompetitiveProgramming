#include <bits/stdc++.h>
#define PI 3.14159265358979323846

using namespace std;

// ACC

int main() {
    ios::sync_with_stdio(0);
    //cin.tie(0);
    double r;
    cin >> r;
    cout << fixed << setprecision(6) << r*r*PI << endl;
    r = r*sqrt(2);
    cout << fixed << setprecision(6) << r*r << endl;
    return 0;
}