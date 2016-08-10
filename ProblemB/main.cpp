#include <bits/stdc++.h>
using namespace std;

int arr[305][305];
int n, m, x;

int memo[305][305];
int memo2[305];

/*
 * ACCEPTED
 */

int maxCol(int i, int j){
    if (i < 0)	return 0;
    if (memo[i][j] != -1) return memo[i][j];
    int res = max(arr[i][j] + maxCol(i-2, j), maxCol(i-1, j));
    return memo[i][j] = res;
}

int dp(int j) {
    if (j < 0) return 0;
    if (memo2[j] != -1) return memo2[j];
    int res = max( maxCol(n-1, j) + dp(j-2), dp(j-1));
    return memo2[j] = res;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    while(cin >> n >> m){
        for (int i=0 ;i<n; i++){
            for (int j=0 ;j<m; j++){
                cin >> arr[i][j];
            }
        }
        memset(memo, -1, sizeof memo);
        memset(memo2, -1, sizeof memo2);
        cout << dp(m-1) << "\n";
    }
    return 0;
}