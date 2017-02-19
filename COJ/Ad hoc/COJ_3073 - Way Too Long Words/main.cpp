#include <bits/stdc++.h>

using namespace std;

// ACC

int main() {
    ios::sync_with_stdio(0);
    //cin.tie(0);
    int cases, ssize;
    string s;
    cin >> cases;
    while (cases--) {
        cin >> s;
        ssize = (int)s.size();
        ssize > 10 ? cout << s[0] << ssize - 2 << s[ssize - 1] : cout << s;
        cout << "\n";
    }
    return 0;
}