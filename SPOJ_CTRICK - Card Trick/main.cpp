#include <iostream>
#include <string.h>

#define MAXN 20000
using namespace std;

int ans[MAXN];

/*
    ACCEPTED
*/

void solve(int n){

    memset(ans, -1, sizeof ans);
    int curr = 1, pos=0, cnt, i;

    while (curr <= n){
        int left = n - curr + 1; // Not located curr
        left = curr%left + 1;

        cnt = 0;
        for (i = pos; ; i++) {
            if (i >= n) i = 0;
            if (ans[i] == -1) cnt++;
            if (cnt == left) break;
        }

        ans[i] = curr;
        pos = i;
        curr++;
    }
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    int T, n;
    cin >> T;
    while(T--){
        cin >> n;
        solve(n);
        for (int i=0; i<n; i++){
            cout << ans[i];
            if (i!=n-1) cout << " ";
        }
        cout << "\n";
    }
    return 0;
}
