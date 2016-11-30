#include <bits/stdc++.h>

using namespace std;

/*
 * ACCEPTED
 */

int resTouch[] = {11, 23, 38, 89, 186, 308, 200, 464, 416}; // results of touching every square
int arr[(1<<9)];

void solve(){
    int res;
    for(int touches=1; touches < (1<<9); touches++){
        res = 0;
        for (int bit = 0; bit < 9; bit++ ){
            if ((1<<bit)&touches) res ^= resTouch[bit];
        }
        arr[res] = touches;
    }
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    int P, board, touches, res;
    char c;

    solve();
    cin >> P;
    while(P--){
        board = 0;
        for (int i=0; i<9; i++){
            cin >> c;
            if (c=='*') board ^= (1<<i);
        }
        touches = arr[board];
        res = 0;
        for (int bit=1; bit <= (1<<9); bit <<=1 ){
            if (bit&touches) res++;
        }
        cout << res << "\n";
    }
    return 0;
}
