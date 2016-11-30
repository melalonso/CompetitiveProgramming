#include <bits/stdc++.h>

using namespace std;

int main() {
    ios::sync_with_stdio(0);
    //cin.tie(0);
    int n;
    cin >> n;

    int arr[n];
    for(int i=0; i<n; i++){
        cin >> arr[i];
    }
    sort(arr, arr+n);
    int mini = 2000010;
    for(int i=0; i<n/2; i++){
        mini = min(mini, arr[i]+arr[n-i-1]);
    }
    cout << mini << "\n";
    return 0;
}