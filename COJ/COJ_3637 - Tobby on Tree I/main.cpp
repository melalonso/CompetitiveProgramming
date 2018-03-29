#include <bits/stdc++.h>

using namespace std;

// ACC
// Problem Multiple Times Applying Reverse

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    string w;
    getline(cin, w);
    stack<char> s;
    for (int i = 0; i < w.size(); i++) {
        if (w[i] == ')') {
            string nw = "";
            while (s.top() != '(') {
                if (s.top() != '(') nw += s.top();
                s.pop();
            }
            s.pop();
            if (s.size()) {
                for (int j = 0; j < nw.size(); j++) s.push(nw[j]);
            } else {
                cout << nw;
            }
        } else if (s.size() || w[i] == '(') {
            s.push(w[i]);
        } else {
            cout << w[i];
        }
    }
    return 0;
}