#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef vector<int> vi;
ll n;

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

ll numPF(ll N) {
    ll PF_idx = 0, PF = primes[PF_idx], ans = 0;
    while (PF * PF <= N) {
        bool flag = true;
        while (N % PF == 0){
            N /= PF;
            if (flag){
                ans++;
                flag = false;
            }
        }
        PF = primes[++PF_idx];
    }
    if (N != 1) ans++;
    return ans;
}

int main() {
    ios::sync_with_stdio(false);
    //cin.tie(0);
    sieve(1000000);
    while (cin >> n && n) {
        cout << n << " : " << numPF(n) << "\n";
    }
    return 0;
}