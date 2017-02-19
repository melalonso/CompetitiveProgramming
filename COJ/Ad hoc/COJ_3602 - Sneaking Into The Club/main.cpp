#include <bits/stdc++.h>

using namespace std;

// ACC, length of words 
// six = 3...

int res[13] = {4, 3, 3, 5, 4, 4, 3, 5, 5, 4, 3, 6, 6};

int main() {
    ios::sync_with_stdio(0);
    //cin.tie(0);
    int n;
    cin >> n;
    cout << res[n] << "\n";
    return 0;
}