#include <bits/stdc++.h>
#define MAXN 300005

using namespace std;

// ACC

double cameras[MAXN];
int m, n;
double answer, pos, curr, r;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    cin >> m >> n >> r;
    //scanf("%d %d %lf", &m, &n, &r);

    cin >> curr;
    //scanf("%lf", &curr);
    cameras[0] = curr;
    for (int i = 1; i < m; i++) {
        cin >> cameras[i];
        //scanf("%lf", &cameras[i]);
    }

    double mxDist = sqrt(r * r - 1); // vertical 1^2 (case 2 -> 2^2, 3^3...)
    double low, high;

    for (int i = 0; i < n; i++) {
        cin >> pos;
        //scanf("%lf", &pos);

        if (pos + mxDist < curr || pos - mxDist > curr) { // choose another camera
            low = *lower_bound(cameras, cameras + m, pos - mxDist);
            high = *prev(upper_bound(cameras, cameras+m, pos + mxDist));
            if (curr - low < high - curr) {
                answer += abs(curr - low);
                curr = low;
            } else {
                answer += abs(curr - high);
                curr = high;
            }

        }
    }

    //printf("%.1lf\n", answer);
    cout << fixed << setprecision(1) << answer << "\n";

    return 0;
}

