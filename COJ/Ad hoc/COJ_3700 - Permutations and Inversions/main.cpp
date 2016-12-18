#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

// ACC

bool arr[50005];
int n;
ll k;

int main() {
    ios::sync_with_stdio(0);
    //cin.tie(0);

    ll start;
    vector<ll> v;
    cin >> n >> k;
    if (k >= n) start = n-1;
    else start = k;
    while (k){
        k -= start;
        v.push_back(start+1);
        arr[start+1] = true;
        start--;
        if (start>k) start = k;
    }
    for (int i=1; i <= n; i++){
        if (!arr[i]) v.push_back(i);
    }
    for (int i=0; i < n; i++){
        cout << v[i];
        if (i<n-1) cout << " ";
    }

    return 0;
}