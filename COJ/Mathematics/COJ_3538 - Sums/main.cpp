#include <bits/stdc++.h>

using namespace std;

// ACC

int isPowerOfTwo(int x) {
    return ((x != 0) && !(x & (x - 1)));
}

int main() {
    ios::sync_with_stdio(0);
    //cin.tie(0);
    //for (int i = 0; i < 50000; i++) cout << rand() % 1000000000 + 1 << "\n";
    //freopen("input", "r", stdin);
    //freopen("output", "w", stdout);
    int cases, n, half, len, x, start;
    cin >> cases;
    while (cases--) {
        cin >> n;
        if (isPowerOfTwo(n) || n == 1) {
            cout << "IMPOSSIBLE\n";
            continue;
        }
        cout << n << " = ";
        if (n % 2) {
            half = n / 2;
            cout << half << " + " << half + 1 << "\n";
        } else {
            len = 3;
            x = n - (len * (len - 1) / 2);
            while (x % len) {
                len++;
                x = n - (len * (len - 1) / 2);
            }
            start = x / len;
            for (int i = 0; i < len; i++) {
                cout << start + i;
                if (i < len - 1) cout << " + ";
            }
            cout << "\n";
        }
    }
    return 0;
}