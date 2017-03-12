#include <bits/stdc++.h>

using namespace std;

int oddUp, oddDown, swithPair;

int main() {
    ios::sync_with_stdio(0);
    //cin.tie(0);
    int n, up, down;
    cin >> n;
    for (int i=0; i<n; i++) {
        cin >> up >> down;
        oddUp += (up%2);
        oddDown += (down%2);
        if ((up%2 + down%2) == 1) swithPair++;
    }

    if (oddDown%2 + oddUp%2 == 0) cout << "0\n";
    else if (oddDown%2 + oddUp%2 == 1) cout << "-1\n";
    else {
        if (swithPair) cout << "1\n";
        else cout << "-1\n";
    }
    return 0;
}