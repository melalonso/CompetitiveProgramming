#include <bits/stdc++.h>

using namespace std;

// ACC

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    int a, b;
    while(cin >> a >> b){
        __gcd(a, b) == 1 ? cout << "YES\n": cout << "NO\n";
    }
    return 0;
}