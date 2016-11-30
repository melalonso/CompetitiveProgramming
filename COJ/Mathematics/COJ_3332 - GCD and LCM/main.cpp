#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
typedef vector<int> vi;


// ACC

ll _sieve_size;
bitset<10000010> bs;
vi primes;


void sieve(ll upperbound) {
    _sieve_size = upperbound + 1;
    bs.set();
    bs[0] = bs[1] = 0;
    for (ll i = 2; i <= _sieve_size; i++)
        if (bs[i]) {
            for (ll j = i * i; j <= _sieve_size; j += i) bs[j] = 0;
            primes.push_back((int) i);
        }
}

int numDiffPF(ll N) {
    int res = 0;
    ll PF_idx = 0, PF = primes[PF_idx];
    while (PF * PF <= N) {
        if (N % PF == 0) res++;
        while (N % PF == 0) { N /= PF; }
        PF = primes[++PF_idx];
    }
    if (N != 1) res++;
    return res;
}

int main() {
    ios::sync_with_stdio(0);
    //cin.tie(0);
    int cases, gcd, lcm, x, power;
    sieve(100000); // Para encontrar los factores primos hasta 10**13
    cin >> cases;
    while (cases--) {
        cin >> gcd >> lcm;
        if (gcd == lcm) {
            cout << 1 << "\n";
        } else if (gcd > lcm || lcm % gcd) {
            cout << 0 << "\n";
        } else {
            x = lcm / gcd;
            power = numDiffPF(x);
            cout << pow(2, power - 1) << "\n";
        }
    }
    return 0;
}