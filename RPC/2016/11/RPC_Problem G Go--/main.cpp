#include <bits/stdc++.h>

#define MAXN 504
using namespace std;

typedef  long long ll;

int game[MAXN][MAXN], black[MAXN][MAXN], white[MAXN][MAXN];
int N, P, x, y;
ll sqBlack, sqWhite;

pair<ll, ll> calc() {
    ll b = 0, w = 0;
    for (int i = 1; i <= N; i++) {
        for (int j = 1; j <= N; j++) {
            black[i][j] = game[i][j] == 2? 0: 1+min(black[i-1][j], min(black[i-1][j-1],black[i][j-1]));
            white[i][j] = game[i][j] == 1? 0: 1+min(white[i-1][j], min(white[i-1][j-1],white[i][j-1]));
            b += max(0, black[i][j]-white[i][j]);
            w += max(0, white[i][j]-black[i][j]);
        }
    }
    return {b, w};
}

int main() {
    ios::sync_with_stdio(0);
    //cin.tie(0);
    while (cin >> N >> P) {
        memset(game, 0, sizeof game);
        for (int i = 0; i < P; i++) {
            cin >> x >> y;
            game[x][y] = 1;
        }
        for (int i = 0; i < P; i++) {
            cin >> x >> y;
            game[x][y] = 2;
        }

        tie(sqBlack, sqWhite) = calc();
        cout << sqBlack << " " << sqWhite << "\n";
    }
    return 0;
}