#include <bits/stdc++.h>

using namespace std;

// ACC

int value[100005];

int bs(int low, int high, int x){
    int mid;
    while(low <= high){
        mid = low + (high-low) / 2;
        if (value[mid] < x){
            low = mid+1;
        }else if (value[mid] > x){
            high = mid-1;
        }else{
            return mid;
        }
    }
    return -1;
}

int main()
{
    int n, q, x;
    cin >> n;
    for (int i=0; i<n; i++) cin >> value[i];
    sort(value, value+n);
    cin >> q;
    while (q--){
        cin >> x;
        cout << bs(0, n-1, x) + 1 << "\n";
    }
    return 0;
}
