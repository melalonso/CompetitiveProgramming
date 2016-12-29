#include <bits/stdc++.h>

#define MAXN 3002

using namespace std;

// ACC

bool memo[MAXN][MAXN];
string s;
int n;

void precalculate() {
    for (int i = 0; i < n; i++) memo[i][i] = true; // single element
    for (int i = 0; i < n; i++) memo[i][i + 1] = true; // two elements
    int s1, s2, mirror;
    for (int len = 3; len <= n; len++) {
        for (int i = 0; i <= n - len; i++) {
            mirror = i + len - 1;
            s1 = s[i] + s[mirror];
            s2 = s[i + 1] + s[mirror - 1];
            memo[i][mirror] = s1 == s2 ? memo[i + 1][mirror - 1] : false;
        }
    }
}

int main() {
    ios::sync_with_stdio(0);
    //cin.tie(0);
    int q, a, b;
    cin >> s;
    n = (int) s.size();
    precalculate();
    cin >> q;
    while (q--) {
        cin >> a >> b;
        if (a > b) swap(a, b);
        cout << (memo[a][b] ? "yes\n" : "no\n");
    }
    return 0;
}