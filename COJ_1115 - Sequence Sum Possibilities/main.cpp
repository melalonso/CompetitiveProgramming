#include <iostream>
#include <bits/stdc++.h>

using namespace std;

/*
    ACCEPTED
 */

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    int T, N, idx, res;
    cin >> T;
    while(T--){
        res = 0;
        cin >> idx >> N;

        for(int i=1; (i*(i+1))/2 < N; i++){
            if (!((N - ((i*(i+1)) / 2))%(i+1))) res++; // Exist an integer "a".
        }
        cout << idx << " " << res << "\n";
    }
    return 0;
}
