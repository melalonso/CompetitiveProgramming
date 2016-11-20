#include <bits/stdc++.h>

using namespace std;

// ACC

bool isDivisible(int div, string n) {
    int num = 0;
    for (int i=0; i < n.size(); i++) {
        num = num*2 + n[i]-48;
        num %= div;
    }
    return !num;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    int cases;
    cin >> cases;
    string n;
    while(cases--) {
        cin >> n;
        if (isDivisible(3, n)) cout << "YES\n";
        else cout << "NO\n";
    }
}
