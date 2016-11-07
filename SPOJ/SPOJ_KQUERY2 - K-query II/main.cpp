#include <bits/stdc++.h>

using namespace std;

const int BLOCK = 500;
int n,q, bit[62][10005];
int arr[30005];

/*
 * ACCEPTED
 */

void update(int i, int x, int y){
    while(x>0) bit[i][x] += y, x -= x&-x;
}

int query(int i, int x) {
    int res=0;
    while(x <= 10000) {
        res += bit[i][x], x += x&-x;
    }
    return res;
}


int main() {
    ios::sync_with_stdio(0);
    //cin.tie(0);
    cin >> n;
    for (int i=1; i<=n; i++){
        cin >> arr[i];
        update(i/BLOCK, arr[i], 1);
    }
    cin >> q;
    int type, l, r, k;
    int idx, val;

    for (int i=0; i<q; i++) {
        cin >> type;
        if (type) {
            cin >> l >> r >> k;
            int ans = 0;
            while(l%BLOCK !=0 && l<=r) ans += arr[l++] > k;
            while(r%BLOCK != BLOCK-1 && l <= r) ans += arr[r--] > k;

            if (r>l) {
                int bl = l/BLOCK;
                int br = r/BLOCK;
                for (int j=bl; j<=br; j++) {
                    ans += query(j, k+1);
                }
            }

            cout << ans << "\n";
        } else {
            cin >> idx >> val;
            update(idx/BLOCK, arr[idx], -1);
            arr[idx] = val;
            update(idx/BLOCK, arr[idx], 1);
        }
    }

    return 0;
}