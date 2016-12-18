#include <bits/stdc++.h>

using namespace std;

int arr[105], n;

// ACC

int solve(){
    int maxx = arr[n-1];
    int maxDiff = 0;
    for (int i=n-2; i>=0; --i){
        if (arr[i]>maxx) maxx = arr[i];
        else{
            maxDiff = max(maxDiff, maxx-arr[i]);
        }
    }
    return maxDiff;
}

int main() {
    ios::sync_with_stdio(0);
    //cin.tie(0);
    cin >> n;
    for (int i=0; i<n; i++) cin >> arr[i];
    cout << solve() << "\n";
    return 0;
}