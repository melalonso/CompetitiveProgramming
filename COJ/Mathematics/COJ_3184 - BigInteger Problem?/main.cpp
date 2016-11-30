#include <bits/stdc++.h>

using namespace std;

// ACC

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    int k, d;
    cin >> k >> d;
    cout << int(ceil( (d-1.0)/log10(k) )) << "\n";
    return 0;
}