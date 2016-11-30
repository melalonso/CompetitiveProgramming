#include <iostream>
#include <stdlib.h>
#include <stdio.h>

#define MAXN 100002
using namespace std;

/*
    ACCEPTED
*/

int fenwick[MAXN], N;

void update(int x){
    while(x < MAXN){ fenwick[x]++, x += x & -x; }
}

int get(int x){
    int res = 0;
    while( x ){ res += fenwick[x], x -= x & -x; }
    return res;
}

int main() {
    freopen("input", "r", stdin);
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> N;
    int arr[N], res[N];

    for(int i = 0; i < N; i++) cin >> arr[i];

    for(int i = N-1; i>=0; i--) {
        res[i] = (N-1-i) - get(arr[i]);
        update( arr[i] );
    }

    for(int i = 0 ; i < N ; i++) {
        cout << res[i];
        if(i < N-1) cout << " ";
    }

    return 0;
}
