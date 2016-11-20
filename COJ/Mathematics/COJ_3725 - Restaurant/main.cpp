#include <bits/stdc++.h>

using namespace std;

// ACC

int main() {
    ios::sync_with_stdio(0);
    //cin.tie(0);
    int T, l,b, gcd;
    cin >> T;
    while(T--){
        cin >> l >> b;
        gcd = __gcd(l, b);
        cout << (l/gcd)*(b/gcd) << "\n";
    }
    return 0;
}