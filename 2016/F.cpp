#include <bits/stdc++.h>
#define MAXN 1000000
#define MOD 987654321

using namespace std;


bitset<1000010> bs;
vector<int> primes;

void sieve(long long ub){
	long long _sieve_size = ub + 5;
	bs.set();
	bs[0] =bs[1]=0;
	for(long long i=2; i <= _sieve_size; i++){
		if ( bs[i] ){
			for(long long j=i*i; j <= _sieve_size; j += i){
				bs[j] = 0;
			}
			primes.push_back((int)i);
		}
	}
}


// 6 / 2 = 3 , 3 / 2 = 1 , 1 / 2 = 0 -> (4+1)
// 6 / 3 = 2 , 2 / 3 = 0 -> (2+1)
// 6 / 5 = 1 , 1 / 5 = 0 -> (1+1)
// 5*3*2 == 30
long long numDiv(long long n){
	long long pf_index = 0, PF = primes[pf_index], ans = 1;
	long long N = n;
	while(PF <= N){
		long long power = 1;
		n = N;
		while (n){
			power += (n / PF);
			n /= PF;
		}
		ans = (ans*power)%MOD;
		PF = primes[++pf_index];
	}
	return ans;
}

int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	int n, k, nDiv, kDiv;
	sieve(MAXN);
	while(cin >> n >> k){
		nDiv = numDiv(n);
		kDiv = numDiv(k);
		cout << (nDiv - kDiv + MOD)%MOD << "\n";
	}
	return 0;
}