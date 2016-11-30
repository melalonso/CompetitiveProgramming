#include <bits/stdc++.h>

using namespace std;

// ACC

bool isVowel(char c) {
    return c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u' ||
           c == 'A' || c == 'E' || c == 'I' || c == 'O' || c == 'U';
}

int main() {
    ios::sync_with_stdio(0);
    //cin.tie(0);
    int n;
    string s;
    cin >> n;
    while (n--) {
        cin >> s;
        isVowel(s[0]) ? cout << s << "cow\n" : cout << s.substr(1,s.size()-1) << s[0] << "ow\n";
    }
    return 0;
}