#include <iostream>

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

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    long long res, N;
    while(cin >> N){
        cout << ( ((N*(N+1))%MOD * ((2*N)-2)%MOD)%MOD * 166666668 )%MOD << "\n";
    }
    return 0;
}
