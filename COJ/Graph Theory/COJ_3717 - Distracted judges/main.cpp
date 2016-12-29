#include <bits/stdc++.h>

#define MAXN 100002
using namespace std;

// ACC

int arr[MAXN];
bool res[MAXN];

int main() {
    ios::sync_with_stdio(0);
    //cin.tie(0);
    int T;
    cin >> T;
    for (int i = 0; i < T; i++) {
        cin >> arr[i];
    }

    res[T] = true;
    for (int j = T - 1; j >= 0; j--) {
        if (j + arr[j] + 1 <= T) {
            res[j] = res[j + arr[j] + 1];
        }
    }

    for (int j = 0; j <= T; j++) {
        if (res[j]) cout << j << "\n";
    }
    return 0;
}