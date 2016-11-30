#include <bits/stdc++.h>

using namespace std;

// ACC

typedef long long ll;

int main() {
    ios::sync_with_stdio(0);
    //cin.tie(0);
    int cases, n, k, x, sum;
    ll res;
    cin >> cases;
    while (cases--) {
        cin >> n >> k;
        int cnt[k];
        fill(cnt, cnt + k, 0);
        cnt[0] = 1;
        sum = 0;
        for (int i = 0; i < n; i++) {
            cin >> x;
            sum = (sum + x) % k;
            cnt[sum]++;
        }

        res = 0;
        for (int j = 0; j < k; j++) {
            res += (long long) cnt[j] * (cnt[j] - 1) / 2;
        }
        cout << res << "\n";
    }
    return 0;
}