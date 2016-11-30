#include <bits/stdc++.h>

#define PI 3.14159

using namespace std;

// ACC


/*
Cone: V = (1/3)PI*R^2*H
Cylinder: V = PI*R^2*H
Sphere: V = (4/3)PI*R^3
*/
int main() {
    ios::sync_with_stdio(0);
    //cin.tie(0);
    double maxVolume = 0, volume, r, h;
    int n;
    char fig;
    cin >> n;
    while (n--) {
        cin >> fig;
        if (fig == 'C') {
            cin >> r >> h;
            volume = (1 / 3.0) * PI * r * r * h * 1.0;
        } else if (fig == 'L') {
            cin >> r >> h;
            volume = PI * r * r * h;
        } else {
            cin >> r;
            volume = (4 / 3.0) * PI * r * r * r;
        }
        maxVolume = max(maxVolume, volume);
    }
    cout << fixed << setprecision(3) << maxVolume << "\n";
    return 0;
}