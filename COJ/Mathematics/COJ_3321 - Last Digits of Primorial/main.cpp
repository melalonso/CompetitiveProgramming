#include <iostream>
#include <bits/stdc++.h>

#define MAX 1000001
#define MOD 10000000000

using namespace std;

typedef vector<int> vi;
typedef long long ll;

ll _sieve_size;
bitset<MAX+100> bs;
vi primes;
ll solutions[MAX];

/*
    ACCEPTED
 */

void sieve(ll upperbound) { // create list of primes in [0..upperbound]
    _sieve_size = upperbound + 1; // add 1 to include upperbound
    bs.set(); // set all bits to 1
    bs[0] = bs[1] = 0; // except index 0 and 1
    for (ll i = 2; i <= _sieve_size; i++) {
        if (bs[i]) {
            for (ll j = i * i; j <= _sieve_size; j += i) bs[j] = 0;
            primes.push_back((int)i); // add this prime to the list of primes
        }
    }
}

void solve() {
    solutions[1] = 1;
    for(int p = 2; p <= 1000000; p++) {
        solutions[p] = solutions[p-1];
        if(bs[p]) {
            solutions[p] *= p;
            solutions[p] %= MOD;
        }
    }
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    int T, N;
    ll res, tmp;
    sieve(MAX), solve();
    cin >> T;
    while(T--){
        cin >> N;
        res = solutions[N];
        if (N>30 && res<1000000000) {
            tmp = res;
            while(tmp%1000000000 == tmp){
                cout << "0";
                tmp *= 10;
            }
        };
        cout << res << "\n";
    }
    return 0;
}
