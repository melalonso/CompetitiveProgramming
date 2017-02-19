#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef vector<int> vi;

// ACC

ll _sieve_size;
bitset<100010> bs;
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

bool isPrime(ll N) {
    if (N <= _sieve_size) return bs[N];
    for (int i = 0; i < (int)primes.size() && (primes[i]*primes[i] <= N); i++)
        if (N % primes[i] == 0) return false;
    return true;
}

int main() {
    ios::sync_with_stdio(0);
    //cin.tie(0);
    int cases;
    ll n;
    sieve(100000); // Para encontrar los factores primos hasta 4*10^9
    cin >> cases;
    while (cases--) {
        cin >> n;
        while(!isPrime(n)) n++;
        cout << n << "\n";
    }
    return 0;
}