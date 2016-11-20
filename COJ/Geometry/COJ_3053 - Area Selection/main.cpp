#include <bits/stdc++.h>
#define PI 3.14

using namespace std;

// ACC

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    int cases;
    double l;
    cin >> cases;
    while(cases--){
        cin >> l;
        l = l*l;
        cout << fixed << setprecision(2) << (PI*l/2.0)- l <<"\n";
    }
    return 0;
}