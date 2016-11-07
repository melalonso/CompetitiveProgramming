#include <bits/stdc++.h>
#define MAXN 62
using namespace std;

typedef unsigned long long ll;

/*
 * ACCEPTED
 */

long long memo[MAXN];
int back;

ll trib(int n)  {
    if (n <= 1) return 1;
    if (memo[n] != -1) return memo[n];
    ll sum = 1;
    for (int i = 1; i <= back; i++)
        sum += trib(n - i);
    return memo[n] = sum;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    int n, index = 1;
    while (cin >> n >> back) {
        if (n > 60) break;
        memset(memo, -1, sizeof memo);
        cout << "Case " << index++ << ": " << trib(n) << "\n";
    }
    return 0;
}