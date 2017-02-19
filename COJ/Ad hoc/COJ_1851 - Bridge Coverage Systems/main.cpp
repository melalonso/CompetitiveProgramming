#include <bits/stdc++.h>

#define MAXN 100002
using namespace std;

// ACC

int tower[MAXN];

int main() {
    ios::sync_with_stdio(0);
    //cin.tie(0);
    int n, maxi = 0;
    cin >> n;

    for (int i = 0; i < n; i++) {
        cin >> tower[i];
        maxi = max(maxi, tower[i]);
    }

    for (int i = 0; i < n; i++) cout << (maxi - tower[i]) << "\n";

    return 0;
}
