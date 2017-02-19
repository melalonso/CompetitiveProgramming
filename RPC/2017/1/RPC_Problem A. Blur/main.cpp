#include <bits/stdc++.h>

using namespace std;

// ACC

long long prevv[102][102];
long long curr[102][102];

int w, h, b;
int mx[8] = {-1, -1, 0, 1, 1,  1,  0, -1};
int my[8] = {0,   1, 1, 1, 0, -1, -1, -1};

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    int nextX, nextY;
    cin >> w >> h >> b;

    for (int j = 0; j < h; j++)
        for (int i = 0; i < w; i++)
            cin >> prevv[j][i];

    int even = 1;
    while (b--) {
        for (int j = 0; j < h; j++){
            for (int i = 0; i < w; i++) {

                long long res = 0;
                if (even) res += prevv[j][i];
                else res += curr[j][i];

                for (int k = 0; k < 8; k++) {
                    nextX = (j + mx[k] + h) % h;
                    nextY = (i + my[k] + w) % w;
                    if (even) res += prevv[nextX][nextY];
                    else res += curr[nextX][nextY];
                }
                if (even) curr[j][i] = res;
                else prevv[j][i] = res;
            }
        }

        even = !even;

    }

    set<long long> myset;
    for (int j = 0; j < h; j++)
        for (int i = 0; i < w; i++){
            if (!even) myset.insert(curr[j][i]);
            else myset.insert(prevv[j][i]);
        }

    cout << myset.size() << "\n";

    return 0;
}