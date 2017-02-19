#include <bits/stdc++.h>

using namespace std;

// ACC

int main() {
    ios::sync_with_stdio(0);
    //cin.tie(0);
    int cases;
    long long n;
    cin >> cases;
    while (cases--) {
        cin >> n;
        if (n % 2) cout << n * 2 << "\n";
        else if (!(n & n - 1)) cout << "1\n";
        else {
            int i = 0;
            while (!(n  & (1 << i))) i++;
            cout << (n / (1<<i)) << "\n";
        }
    }
    return 0;
}
