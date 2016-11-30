#include <bits/stdc++.h>

using namespace std;

// ACC
// Se puede resolver con modExp

int pattern[10][4] = {{0,0,0,0}, {1,1,1,1}, {2,4,8,6}, {3,9,7,1},
                      {4,6,4,6}, {5,5,5,5}, {6,6,6,6}, {7,9,3,1}, {8,4,2,6}, {9,1,9,1}};

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    int cases, a, b, last_digit_base, mod;
    cin >> cases;
    while(cases--){
        cin >> a >> b;
        if (!b){
            cout << 1 <<"\n";
            continue;
        }
        mod = b%4;
        last_digit_base = a%10;
        cout << pattern[last_digit_base][(mod-1+4)%4] << "\n";
    }
    return 0;
}