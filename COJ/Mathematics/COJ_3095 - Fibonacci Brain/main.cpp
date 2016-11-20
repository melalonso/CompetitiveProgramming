#include <bits/stdc++.h>

#define  MAXN 60

using namespace std;

// ACC

int fib[MAXN] = {0};

void calc() {
    fib[0] = 0, fib[1] = 1;
    for (int i = 2; i <= MAXN; i++) {
        fib[i] = (fib[i - 1] + fib[i - 2]) % 10;
    }
}

int main() {
    ios::sync_with_stdio(false);
    //cin.tie(0);
    long long n;
    calc();
    while (cin >> n) {
        cout << fib[n % 60] << "\n";
    }
    return 0;
}