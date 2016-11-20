#include <bits/stdc++.h>

using namespace std;

// ACC

int main() {
    ios::sync_with_stdio(0);
    //cin.tie(0);
    int T, R;
    cin >> T;
    double sqrt3 = sqrt(3);
    while(T--){
        cin >> R;
        cout << setprecision(1) << fixed << R*sqrt3-R << "\n";
    }
    return 0;
}