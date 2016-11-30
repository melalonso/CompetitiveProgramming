#include <bits/stdc++.h>

using namespace std;

// ACC

int main() {
    ios::sync_with_stdio(0);
    //cin.tie(0);
    int cases;
    bool flag;
    string s, p;
    cin >> cases;
    while (cases--) {
        cin >> s >> p;
        flag = false;
        int ssize = s.size();
        if (ssize != p.size()) {
            cout << "NO\n";
            continue;
        }
        for (int i = 0; i < s.size(); i++) {
            if (s[i] != p[i]) {
                if (s[ssize - i - 1] != p[i] || s[i] != p[ssize - i - 1]) {
                    flag = true;
                    break;
                }
            }
        }
        flag ? cout << "NO\n" : cout << "YES\n";
    }
    return 0;
}