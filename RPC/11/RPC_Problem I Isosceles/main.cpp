#include <bits/stdc++.h>
#define MAXN 50005
using namespace std;

// ACC

int arr[MAXN];
int left1[MAXN];
int right1[MAXN];

int main() {
    ios::sync_with_stdio(0);
    //cin.tie(0);
    int n, v;
    while(cin >> n){
        for (int i=0; i<n; i++) cin >> arr[i];

        left1[0] = 1;
        for (int i=1; i<n; i++){
            left1[i] = min(arr[i], left1[i-1]+1);
        }

        right1[n-1] = 1;
        for (int i=n-2; i>=0; i--){
            right1[i] = min(arr[i], right1[i+1]+1);
        }

        int res=0;
        for (int i=0; i<n; i++){
            res = max(res, min(left1[i], right1[i]));
        }
        cout << res<<"\n";

    }

    return 0;
}