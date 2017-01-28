#include <bits/stdc++.h>

using namespace std;

// ACC

int main() {
    ios::sync_with_stdio(0);
    //cin.tie(0);
    //print();
    string s;
    int val;
    vector<int> res;
    cin >> s;
    for (int i = s.size() - 1; i >= 0; i -= 3) {
        val = 0;
        if (s[i] == '1') val++;
        if (i - 1 >= 0 && s[i - 1] == '1') val += 2;
        if (i - 2 >= 0 && s[i - 2] == '1') val += 4;
        res.push_back(val);
    }
    for (int i=res.size()-1; i>=0; i--) cout << res[i];

    return 0;
}