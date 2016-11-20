#include <bits/stdc++.h>

using namespace std;

// ACC

int main() {
    ios::sync_with_stdio(0);
    //cin.tie(0);
    int T, N, x;
    set<int> myset;
    cin >> T;
    while (T--) {
        cin >> N;
        for (int i = 0; i < N; i++) {
            cin >> x;
            if (myset.find(x) != myset.end()) cout << x << "\n";
            else myset.insert(x);
        }
        if (myset.size()==N) cout << "Not found!\n";
        myset.clear();
    }
    return 0;
}