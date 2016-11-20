#include <bits/stdc++.h>

using namespace std;

// ACC

int main() {
    ios::sync_with_stdio(0);
    //cin.tie(0);
    int gunnar = 0, emma = 0, x;

    for(int i=0; i<4; i++){
        cin >> x; gunnar += x;
    }

    for(int i=0; i<4; i++){
        cin >> x; emma += x;
    }

    if(emma > gunnar) cout << "Emma\n";
    else if(gunnar > emma) cout << "Gunnar\n";
    else cout << "Tie\n";

    return 0;
}