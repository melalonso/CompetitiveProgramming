#include <bits/stdc++.h>

using namespace std;

/*
    ACCEPTED
 */

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    int k;
    string line;
    cin >> k;
    getline(cin, line);
    while (k--) {
        getline(cin, line);
        int ssize = (int) line.size();
        for (int i = 0; i < ssize; i++) {
            if (line[i] >= 'A' && line[i] <= 'Z') cout << (char)(line[i] + 32);
            else if (line[i] >= 'a' && line[i] <= 'z') cout << (char)(line[i] - 32);
            else cout << (char)line[i];
        }
        cout << "\n";
    }
    return 0;
}