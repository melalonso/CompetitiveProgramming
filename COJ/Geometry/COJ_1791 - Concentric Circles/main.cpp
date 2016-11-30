#include <bits/stdc++.h>
# define PI 3.14159265358979323846

// ACC

using namespace std;

int main() {
    ios::sync_with_stdio(0);
    //cin.tie(0);
    int n, start;
    double res = 0;
    cin >> n;
    int c[n];
    for (int i=0;i<n; i++) cin >> c[i];
    sort(c, c+n);
    if (n%2){
        res += c[0]*c[0]*PI; start = 0;
    } else {
        res += ( (c[1]*c[1]*PI) - (c[0]*c[0]*PI)); start = 1;
    }

    for (int i=start+2; i<n; i+=2){
        res += ((c[i]*c[i]*PI)-(c[i-1]*c[i-1]*PI));
    }

    cout << fixed << setprecision(4) << res << "\n";

    return 0;
}