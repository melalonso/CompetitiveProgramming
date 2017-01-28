#include <bits/stdc++.h>

#define MAXN 1005
#define MAXP 105

using namespace std;

typedef long long ll;

// ACC

ll hashArr1[MAXP], hashTable[MAXN][MAXN];
char tx[MAXN][MAXN], pt[MAXP][MAXP];
int cases, n, m, x, y;
ll p1 = 997, p2 = 99991, mod1 = 1000000007, mod2 = 10000019;

// Horner's method
//  a0x4 + a2x3 + a3x2 + a4x1 + a5 = ( ( ( a0x + a1 ) x + a2 ) x + a3 ) x + a5
ll hashPattern() {
    ll r;
    for (int i = 0; i < x; i++) {
        r = 0;
        for (int j = 0; j < y; j++) {
            r = (r * p1 + pt[i][j]) % mod1;
        }
        hashArr1[i] = r;
    }
    r = 0;
    for (int j = 0; j < x; j++) {
        r = (r * p2 + hashArr1[j]) % mod2;
    }
    return r;
}

void hashText() {
    ll power = 1, r;
    for (int i = 1; i < y; i++) power = (power * p1) % mod1;

    for (int i = 0; i < n; i++) {
        r = 0;
        for (int j = 0; j < y; j++) {
            r = (r * p1 + tx[i][j]) % mod1;
        }
        hashTable[i][0] = r;
        for (int j = 1; j < m - y + 1; j++) {
            r = (((r - tx[i][j - 1] * power) % mod1) + mod1) % mod1;
            r = (r * p1 + tx[i][j + y - 1]) % mod1;
            hashTable[i][j] = r;
        }
    }

    power = 1;
    for (int i = 1; i < x; i++) power = (power * p2) % mod2;

    for (int j = 0; j < m - y + 1; j++) {
        r = 0;
        for (int i = 0; i < x; i++) {
            r = (r * p2 + hashTable[i][j]) % mod2;
        }
        for (int i = 0; i < n - x + 1; i++) {
            ll tmp = r;
            r = ((r - hashTable[i][j] * power) % mod2 + mod2) % mod2;
            r = (r * p2 + hashTable[i + x][j]) % mod2;
            hashTable[i][j] = tmp;
        }
    }
}

int solve() {
    int result = 0;
    ll hashP = hashPattern();
    hashText();
    for (int i = 0; i < n - x + 1; i++)
        for (int j = 0; j < m - y + 1; j++)
            if (hashTable[i][j] == hashP) result++;
    return result;
}

int main() {
    ios::sync_with_stdio(0);
    //cin.tie(0);
    cin >> cases;
    while (cases--) {
        cin >> n >> m;
        for (int i = 0; i < n; i++) cin >> tx[i];
        cin >> x >> y;
        for (int i = 0; i < x; i++) cin >> pt[i];
        cout << solve() << "\n";
    }
    return 0;
}