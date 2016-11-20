#include <bits/stdc++.h>
#define PI 3.14

using namespace std;

// ACC

int main() {
    ios::sync_with_stdio(0);
    //cin.tie(0);
    int cases, radio;
    cin >> cases;
    double sqrt3 = sqrt(3);
    while(cases--){
        cin >> radio;
        radio = radio*radio;
        cout << fixed << setprecision(2) << (radio*sqrt3)-(PI*radio/2.0) <<"\n";
    }
    return 0;
}