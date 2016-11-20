#include <bits/stdc++.h>

#define MAXN 14500

using namespace std;

// ACC

int arr[MAXN];

int sum(int n) {
    return n * (n + 1) / 2;
}

void calc() {
    for (int i = 0; i <= MAXN; i++) arr[i] = sum(i);
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    calc();
    int s;
    while (cin >> s && s) {
        auto pos = upper_bound(arr, arr + MAXN, s);
        int idx = distance(begin(arr), pos);
        if (arr[idx - 1] == s) cout << idx << " "<<idx <<"\n";
        else cout << arr[idx] - s << " "<<idx << "\n";
    }
    return 0;
}