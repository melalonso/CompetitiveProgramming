#include <bits/stdc++.h>

using namespace std;

// ACC

int main() {
    ios::sync_with_stdio(0);
    //cin.tie(0);
    int cases, m, w;
    cin >> cases;
    while (cases--) {
        cin >> m >> w;
        int ele[m];
        for (int i = 0; i < m; i++) cin >> ele[i];
        sort(ele, ele + m);
        int idx = 0;
        while (idx < m && w >= ele[idx]){
            w -= ele[idx++];
        }
        cout << idx << "\n";
    }
    return 0;
}