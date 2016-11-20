#include <bits/stdc++.h>

using namespace std;

// ACC

int main() {
    ios::sync_with_stdio(0);
    //cin.tie(0);
    int prev, curr;
    cin >> prev;
    for (int i = 0; i < 10; i++) {
        curr = (prev * 13821) % 32768;
        cout << curr << " : " << curr % 7 + 1 << "\n";
        prev = curr;
    }

    return 0;
}