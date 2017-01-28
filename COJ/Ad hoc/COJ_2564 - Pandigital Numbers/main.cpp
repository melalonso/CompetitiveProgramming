#include <bits/stdc++.h>

using namespace std;

// ACC

int main() {
    ios::sync_with_stdio(0);
    //cin.tie(0);
    int cases;
    long long n;
    cin >> cases;
    while (cases--){
        cin >> n;
        (n&n+1) ? cout << "YES\n" : cout << "NO\n";
    }
    return 0;
}