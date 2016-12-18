#include <bits/stdc++.h>

using namespace std;

// ACC

int arr[55];

int main() {
    ios::sync_with_stdio(0);
    //cin.tie(0);
    int cases, n;
    cin >> cases;
    while (cases--) {
        cin >> n;
        for (int i=0; i<n; i++) cin >> arr[i];

        int acc;
        bool flag=0;
        for (int i=0; i<n; i++){
            acc = 0;
            for (int j=i; j<n; j++){
                acc += arr[j];
                if (!acc) {
                    flag=1;
                    break;
                }
            }
            if (flag){
                cout << "YES\n";
                break;
            }
        }
        if (!flag) cout << "NO\n";

    }
    return 0;
}