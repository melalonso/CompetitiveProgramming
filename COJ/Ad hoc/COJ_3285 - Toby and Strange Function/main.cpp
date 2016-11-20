#include <bits/stdc++.h>

using namespace std;
typedef  long long ll;

// ACC

int main() {
    ios::sync_with_stdio(0);
    //cin.tie(0);
    int T;
    ll n, size;
    string S;
    cin >> T;
    while (T--) {
        cin >> n;
        cin >> S;
        size = S.size();
        n %= size;
        cout << S.substr(size-n, n) << S.substr(0, size-n) << "\n";
    }
    return 0;
}