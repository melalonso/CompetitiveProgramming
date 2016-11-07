#include <bits/stdc++.h>

using namespace std;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    int cases, n, changes;
    int curr, prev, first;
    cin >> cases;
    while(cases--){
        cin >> n;
        changes = 0;
        cin >> prev;
        first = prev;
        for(int i=1; i<n; i++){
            cin >> curr;
            if (curr+1==prev) changes++;
            prev = curr;
        }
        if (first !=1 && prev-2 >= first) changes++;
        cout << changes*2 << "\n";
    }
    return 0;
}