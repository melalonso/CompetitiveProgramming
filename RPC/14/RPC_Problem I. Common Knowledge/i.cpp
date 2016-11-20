#include <bits/stdc++.h>

using namespace std;

int main() {
	ios::sync_with_stdio(0);
    cin.tie(0);
    
    int n;
    while(cin >> n){
        long long res = pow(8, n);
        cout << res << "\n";
    }
    return 0;
}