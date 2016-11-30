#include <iostream>
#include <bits/stdc++.h>

/*
    UVA ACCEPTED
    COJ ACCEPTED
 */

#define MAX 1000001
using namespace std;

typedef vector<int> vi;
typedef long long ll;

ll _sieve_size;
bitset<MAX+100> bs;
vi primes;

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

bool isPrime(ll n){
    return bs[n];
}

int findPrimes(ll n) {
    int idx =  (lower_bound(primes.begin(), primes.end(), n) - primes.begin() ) - 1;

    for(ll i = idx; i>=0; i--) {
        if (isPrime(n-primes[i])) {
            cout << n << " = " << n-primes[i] << " + "<< primes[i] << "\n";
            break;
        }
    }
    return 0;
}

int main()
{
    ios::sync_with_stdio(0); // Dont forget these fucking lines haha TLE
    cin.tie(0);
    int n;
    sieve(MAX+10);
    while(cin >> n, n) {
        findPrimes(n);
    }
    return 0;
}