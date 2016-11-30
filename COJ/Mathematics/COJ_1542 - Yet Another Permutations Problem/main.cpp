#include <iostream>
#include <stdio.h>
#include <stdlib.h>

#define MOD 1000000007

using namespace std;
typedef long long ll;

/*
    ACCEPTED
*/

ll modExp(ll base, int exp){
    ll r = 1;
    base%=MOD;
    while (exp){
        if (exp&1) r=(r*base)%MOD;
        base=(base * base) % MOD;
        exp>>=1;
    }
    return r;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    int T, N;
    cin >> T;
    while(T--){
        cin >> N;
        cout << modExp(2, N-1) % MOD << "\n";
    }
}
