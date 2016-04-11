// Imports.

#include <iostream>
#include <stdlib.h>
#include <stdio.h>
#include <vector>
#include <map>
#include <algorithm>
#include <string>
#include <cstring>
#include <sstream>
#include <iomanip>
#include <bitset>
#include <queue>
#include <stack>
#include <math.h>

using namespace std;

/*
    ACCEPTED
*/

typedef long long ll;
typedef vector<int> vi;


vi facts;
ll _sieve_size;
bitset<110> bs;
vi primes;

void sieve(ll upperbound) {
    _sieve_size = upperbound + 1;
    bs.set();
    bs[0] = bs[1] = 0;
    for (ll i = 2; i <= _sieve_size; i++) if (bs[i]) {
        for (ll j = i * i; j <= _sieve_size; j += i) bs[j] = 0;
        primes.push_back((int)i);
    }
}

vi primeFactors(ll N) {
    vi factors;
    ll PF_idx = 0, PF = primes[PF_idx];
    while (PF * PF <= N) {
        if (N%PF==0) factors.push_back(PF);
        while (N % PF == 0) N /= PF;
        PF = primes[++PF_idx];
    }
    if (N != 1) factors.push_back(N);
    return factors;
}

// Returns count of coprimes with with N up to C
ll count(ll C) {
    if( !C ) return 0;
    int cnt;
    ll res = 0;
    long double prod, cp;
    for(int mask = 1; mask < (1<<facts.size()); mask++) {
        prod = 1, cnt = 0;
        for(int i = 0; i < facts.size(); i++) if( mask & (1<<i) ){
            cnt++;
            prod *= facts[i];
        }
        cp = C / prod;
        if(cnt % 2) res += floor(cp);
        else res -= floor(cp);
    }
    return C-res;
}

int main()
{
    freopen("input", "r", stdin);
    ios::sync_with_stdio(0);
    cin.tie(0);
    sieve(100);

    int G, A, R, rng[4];
    ll a_ans, g_ans;
    int a_pts=0, g_pts=0;

    cin >> G >> A;
    cin >> R;
    while(R--) {
        cin >>rng[0]>>rng[1]>>rng[2]>>rng[3];
        cin >> a_ans >> g_ans;

        facts = primeFactors(G);
        if (count(rng[1])-count(rng[0]-1) == a_ans) a_pts+=2;
        else a_pts--;

        facts = primeFactors(A);
        if (count(rng[3])-count(rng[2]-1) == g_ans) g_pts+=2;
        else g_pts--;
    }

    if (g_pts > a_pts) cout << "Garfield wins";
    else if (g_pts < a_pts) cout <<"Anders wins";
    else cout << "Draw";

    return 0;
}
