#include <bits/stdc++.h>

using namespace std;

// ACC

int main() {
    ios::sync_with_stdio(false);
    //cin.tie(false);
    int C, n, left, entered, stayed, curr;
    cin >> C >> n;
    curr = 0;
    while (n--) {
        cin >> left >> entered >> stayed;

        if (curr - left < 0) {
            cout << "impossible\n";
            return 0;
        }
        curr -= left;
        if (curr + entered > C) {
            cout << "impossible\n";
            return 0;
        }
        curr += entered;
        if (stayed && curr < C) {
            cout << "impossible\n";
            return 0;
        }
    }
    if (!curr) cout << "possible\n";
    else cout << "impossible\n";
    return 0;
}