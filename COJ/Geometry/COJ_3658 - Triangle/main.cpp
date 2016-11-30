#include <bits/stdc++.h>

using namespace std;
double t1[3], t2[3];

// ACC

bool equals() {
    return t1[0] == t2[0] && t1[1] == t2[1] && t1[2] == t2[2];
}

bool check() {
    return (hypot(t1[0], t1[1]) == t1[2]) && equals();
}

int main() {
    ios::sync_with_stdio(0);
    //cin.tie(0);
    cin >> t1[0] >> t1[1] >> t1[2];
    cin >> t2[0] >> t2[1] >> t2[2];
    sort(t1, t1 + 3);
    sort(t2, t2 + 3);
    check() ? cout << "YES\n" : cout << "NO\n";
    return 0;
}