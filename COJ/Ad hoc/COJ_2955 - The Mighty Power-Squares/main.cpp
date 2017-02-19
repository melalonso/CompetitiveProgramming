#include <bits/stdc++.h>

using namespace std;

// ACC

typedef long long ll;

int main() {
    ios::sync_with_stdio(0);
    //cin.tie(0);
    int cases, raizA;
    ll a, b;
    cin >> cases;
    while(cases--){
        cin >> a >> b;
        raizA = (int) sqrt(a);

        long long curr = pow(2, (int) log2(raizA));
        long long res = 0, low = a, next1, high;

        while (curr*curr <= b){
            next1 = curr * 2;

            high = min(next1 * next1, b+1);
            res += ( (high - low) * curr );

            low = max(high, a);
            curr = next1;
        }
        cout << res << "\n";
    }
    return 0;
}