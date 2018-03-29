#include <bits/stdc++.h>

#define forr(i, a, b) for(int i=(a); i<(b); i++)
#define forn(i, n) forr(i,0,n)
#define sz(c) ((int)c.size())
#define zero(v) memset(v, 0, sizeof(v))
#define dforn(i, n) for(int i=n-1; i>=0; i--)

#define MAXN 10000000 + 5
#define TOTAL 200000 + 5

using namespace std;

int n, maxVal;
int arr[TOTAL], BITree[MAXN];

int getSum(int index) {
    int sum = 0;
    while (index > 0) {
        sum += BITree[index];
        index -= index & (-index);
    }
    return sum;
}

void updateBIT(int index) {
    while (index <= maxVal) {
        BITree[index]++;
        index += index & (-index);
    }
}

/*void convert() {
    int temp[n];
    for (int i = 0; i < n; i++) temp[i] = arr[i];
    sort(temp, temp + n);

    for (int i = 0; i < n; i++) {
        arr[i] = lower_bound(temp, temp + n, arr[i]) - temp + 1;
    }
}*/

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int cases;
    cin >> cases;
    while (cases--) {
        cin >> n;
        maxVal = 0;
        forn(i, n) {
            cin >> arr[i];
            maxVal = max(maxVal, arr[i]);
        }
        //convert();
        fill(BITree, BITree + MAXN, 0);

        long long total = 0;
        dforn(i, n) {
            total += getSum(arr[i] - 1);
            updateBIT(arr[i]);
        }
        cout << total << "\n";

    }
    return 0;
}