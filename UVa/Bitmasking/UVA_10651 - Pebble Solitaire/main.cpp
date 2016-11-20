#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <algorithm>
#include <vector>
#include <string>
#include <queue>
#include <limits.h>
#include <bitset>

#define size 12

using namespace std;
typedef long long ll;

ll bt(int mask){
    ll res = 0;
    int newmask = mask;
    for (int i=0; i<size; i++){
        if (! (mask & 1<<i)) continue;
        if (i>1){ // right movement
            if ( (mask & 1<<(i-1)) && !(mask & 1<<(i-2)) ) {
                res = max(res, 1 + dp(mask & ~(1<<i) & ~(1<<i-1 )| 1<<(i-2) ) );
            }
        }
        if (i<size-2){ // left movement
            if ( (mask & 1<<(i+1)) && !(mask & 1<<(i+2)) ) {
                res = max(res, 1 + dp(mask & ~(1<<i) & ~(1<<i+1 )| 1<<(i+2) ) );
            }
        }
    }
    return res;
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    char c;
    int n, bitmask, on;
    freopen("input", "r", stdin);
    cin >> n;
    while (n--) {
        on = bitmask = 0;
        for (int i=size-1; i>=0; i--){
            cin >> c;
            if (c=='o') bitmask = bitmask | 1<<i, on++;
        }
        cout << on-bt(bitmask) << "\n";
    }

    return 0;
}
