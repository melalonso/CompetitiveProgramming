#include <bits/stdc++.h>

using namespace std;

// ACC

int main() {
    ios::sync_with_stdio(0);
    //cin.tie(0);
    string a, b;
    bool flag = true;
    int ssize;
    cin >> a >> b;
    a += b;
    ssize = (int) a.size();
    for (int i = 0; i <= ssize / 2; i++) {
        if (a[i] != a[ssize-i-1]){
            flag = false; break;
        }
    }
    if (flag) cout << "Yes\n";
    else cout << "No\n";
    return 0;
}