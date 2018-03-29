#include <bits/stdc++.h>

using namespace std;
#define forr(i, a, b) for(int i=(a); i<(b); i++)
#define forn(i, n) forr(i,0,n)
#define sz(c) ((int)c.size())
#define zero(v) memset(v, 0, sizeof(v))
#define dforn(i, n) for(int i=n-1; i>=0; i--)

typedef long long ll;
int letters[26];

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    string str;
    cin >> str;
    forn(i, sz(str)) {
        letters[str[i] - 'a']++;
    }

    int impares = 0;
    for (int i = 0; i < 26; i++) {
        if (letters[i] % 2) impares++;
    }

    if (impares > 1) {
        cout << "NO\n";
    } else {
        cout << "YES\n";
    }


    return 0;
}