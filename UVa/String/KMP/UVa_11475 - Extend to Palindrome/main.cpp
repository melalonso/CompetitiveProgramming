#include <bits/stdc++.h>

#define MAXN 100005

using namespace std;

// ACC

string P, T;
int b[MAXN], n, len;

void kmpPreprocess() {
    int i = 0, j = -1;
    b[0] = -1;
    while (i < n) {
        while (j >= 0 && P[i] != P[j]) j = b[j];
        i++, j++;
        b[i] = j;
    }
}

int kmpSearch() {
    int i = 0, j = 0;
    while (i < n) {
        while (j >= 0 && T[i] != P[j]) j = b[j];
        i++, j++;
        if (j == n) return j;
    }
    return j;
}

int main() {
    ios::sync_with_stdio(0);
    //cin.tie(0);
    while (cin >> T) {

        n = (int) T.size();
        P = T;
        reverse(P.begin(), P.end());

        kmpPreprocess();
        len = kmpSearch();

        cout << T;
        for (int i = n - len - 1; i >= 0; i--) cout << T[i];
        cout << "\n";

    }
    return 0;
}