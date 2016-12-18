#include <bits/stdc++.h>

using namespace std;

// ACC

int main() {
    ios::sync_with_stdio(0);
    //cin.tie(0);
    double n;
    long double bin3By2;
    while(cin >> n && n){
        // binomial(n, 3) * 2
        bin3By2 = (n*(n+1))/3;
        cout << fixed << setprecision(6) << sqrt(bin3By2) << "\n";
    }
    return 0;
}