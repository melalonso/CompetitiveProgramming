#include <bits/stdc++.h>

using namespace std;

// ACC

int cases, n, arr[105];
int start1, end1;

int solve(){
    if (n==1) return 0;
    int res, i;
    res = i = 0;
    while (i < n-1){
        while (i < n-1 && arr[i+1]<= arr[i]) i++;
        start1 = i++;
        while (i < n && arr[i] >= arr[i-1]) i++;
        end1 = i-1;
        res += arr[end1] - arr[start1];
    }
    return res;
}

int main() {
    ios::sync_with_stdio(0);
    //cin.tie(0);
    cin >> cases;
    while (cases--) {
        cin >> n;
        for (int i = 0; i < n; i++) cin >> arr[i];
        cout << solve() << "\n";
    }
    return 0;
}