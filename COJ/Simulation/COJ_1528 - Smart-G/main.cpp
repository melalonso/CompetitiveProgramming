#include <bits/stdc++.h>

using namespace std;

// ACC

typedef pair<int, int> ii;

ii cars[2550];
int elev[60];

int main() {
    ios::sync_with_stdio(0);
    //cin.tie(0);
    int cases, h, l, n, x, movs;
    long long res;
    cin >> cases;
    while (cases--) {
        cin >> h >> l;
        res = n = 0;
        for (int i = 0; i < h; i++) {
            for (int j = 0; j < l; j++) {
                cin >> x;
                if (x != -1) {
                    n++;
                    cars[x - 1] = {i, j};
                }
            }
        }

        fill(elev, elev+60, 0);
        int fl, pos, a, b;
        for (int i = 0; i < n; i++) {
            tie(fl, pos) = cars[i];
            res += (fl * 20); // Going doing to floor 0.s
            a = max(elev[fl], pos);
            b = min(elev[fl], pos);
            movs = min(a-b, (l-a)+b);
            res += (movs * 5);
            elev[fl] = pos;
        }


        cout << res << "\n";
    }
    return 0;
}