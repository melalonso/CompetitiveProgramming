#include <bits/stdc++.h>

using namespace std;

// ACC

int main() {
    ios::sync_with_stdio(0);
    //cin.tie(0);
    long long n, m, total;
    long long res;
    while (cin >> n >> m && n && m) {
        total = n * m;
        res = 4 * total - 16; // Esquinas
        res += (total - 6) * (2 * n + 2 * m - 8); // Bordes
        res += (total-9)*((n-2)*(m-2)); // Centros
        cout << res << "\n";
    }
    return 0;
}