#include <bits/stdc++.h>
#include <utility>

#define forr(i, a, b) for(int i=(a); i<(b); i++)
#define forn(i, n) forr(i,0,n)
#define sz(c) ((int)c.size())
#define zero(v) memset(v, 0, sizeof(v))
#define dforn(i, n) for(int i=n-1; i>=0; i--)


// ACC

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n;
    set<int> digits;
    bool f = false;
    while (cin >> n && n) {
        bool found = false;
        if (f) cout << "\n";
        for (int den = 1234; den <= (98765 / n) + 1; den++) {
            digits.clear();
            if (den < 10000) digits.insert(0);
            int num = n * den;
            int tmp1 = den, tmp2 = num;
            while (tmp1) {
                digits.insert(tmp1 % 10);
                tmp1 /= 10;
            }
            while (tmp2) {
                digits.insert(tmp2 % 10);
                tmp2 /= 10;
            }
            if (digits.size() == 10) {
                found = true;
                cout << num << " / ";
                if (den < 10000) cout << "0";
                cout << den << " = " << n << "\n";
            }
        }
        f = true;
        if (!found) {
            cout << "There are no solutions for " << n << ".\n";
        }
    }
    return 0;
}