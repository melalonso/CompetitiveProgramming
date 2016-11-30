#include <bits/stdc++.h>

using namespace std;

// ACC

string s;
int v, c;

bool isVowel(char c) {
    return c == 'A' || c == 'E' || c == 'I' || c == 'O' || c == 'U';
}

int main() {
    ios::sync_with_stdio(0);
    //cin.tie(0);
    cin >> s;
    for (int i = 0; i < s.size(); i++) {
        if (isVowel(s[i])) v++;
        else c++;
    }
    cout << v << " " << c << "\n";
    return 0;
}