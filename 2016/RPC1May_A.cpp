#include <bits/stdc++.h>
#define MOD 10000000000
using namespace std;

typedef unsigned long long ll;

int main() {
	ll n, res;
	while(cin >> n, n) {
		if (n & 1){
			res = ((n + 1) / 2 * (n + 1) / 2)%MOD;
			res = ((res * n)%MOD * n)%MOD;
		} else {
			res = (n / 2 * n / 2)%MOD;
			res = ((res * (n + 1))%MOD * (n + 1))%MOD;
		}
		
		cout << res << "\n";
	}
	return 0;
}