#include <bits/stdc++.h>

using namespace std;

// ACC

int main() {
    ios::sync_with_stdio(0);
    //cin.tie(0);
    int cases, res;
    string s1, s2;
    cin >> cases;
    while (cases--) {
        res = 0;
        cin >> s1 >> s2;
        for (int i = 0; i < s1.size(); i++) {
            if (s1[i] != s2[i]) res++;
        }
        cout << res << "\n";
    }
    return 0;
}