#include <bits/stdc++.h>

using namespace std;

// ACC

int arr[465];

int main() {
    ios::sync_with_stdio(0);
    //cin.tie(0);
    int n, idx, res;
    for (int i = 1; i < 465; i++) arr[i] = i * i * i;
    while (cin >> n && n) {
        res = 1;
        idx = 2;
        while (idx < 465 && n >= arr[idx]) {
            if (n % arr[idx++] == 0) res++;
        }
        cout << res << "\n";
    }

    return 0;
}