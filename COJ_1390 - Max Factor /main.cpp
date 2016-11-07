#include <bits/stdc++.h>

using namespace std;
typedef vector<int> vi;

int _sieve_size;
bitset<20010> bs;
vi primes;
int largestPrimeFactor = 0;

// ACC

void sieve(int upperbound) {
    _sieve_size = upperbound + 1;
    bs.set();
    bs[0] = bs[1] = 0;
    for (int i = 2; i <= _sieve_size; i++)
        if (bs[i]) {
            for (int j = i * i; j <= _sieve_size; j += i) bs[j] = 0;
            primes.push_back(i);
        }
}


int primeFactors(int N) {
    vi factors;
    int PF_index = 0, PF = primes[PF_index];
    while (PF * PF <= N) {
        while (N % PF == 0) {
            N /= PF;
            factors.push_back(PF);
        }
        PF = primes[++PF_index];
    }
    if (N != 1) factors.push_back(N);
    if (N==1) return 0;
    else return factors[factors.size() - 1];
}

int main() {
    ios::sync_with_stdio(0);
    //cin.tie(0);
    int cases, x, res;
    sieve(20000);
    cin >> cases;
    primeFactors(1);
    while (cases--) {
        cin >> x;
        int bf = primeFactors(x);
        if (bf > largestPrimeFactor) {
            largestPrimeFactor = bf;
            res = x;
        }
    }
    cout << res << "\n";
    return 0;
}