#include <bits/stdc++.h>

using namespace std;

// ACC

int main() {
    ios::sync_with_stdio(0);
    //cin.tie(0);
    int n, res = 0;
    cin >> n;
    while(n){
        n >>= 1;
        res++;
    }
    cout << res << "\n";
    return 0;
}