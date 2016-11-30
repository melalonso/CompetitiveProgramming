#include <bits/stdc++.h>

using namespace std;


// ACC

int main() {
    ios::sync_with_stdio(0);
    //cin.tie(0);
    int n, k, noStopTime;
    double lapsedTime,tmpN;
    cin >> n >> k;
    int info[k][3];
    for (int i = 0; i < k; i++) {
        cin >> info[i][0] >> info[i][1] >> info[i][2];
        tmpN = n;
        lapsedTime = 0.0;
        noStopTime = 0;
        while (tmpN) {
            if (noStopTime == info[i][1]) {
                noStopTime = 0;
                lapsedTime += info[i][2];
                continue;
            }
            if (tmpN >= info[i][0]) {
                tmpN -= info[i][0];
                lapsedTime++;
                noStopTime++;
            } else {
                lapsedTime += (tmpN / info[i][0]);
                tmpN -= tmpN;
            }
        }

        cout << ceil(lapsedTime) << "\n";
    }

    return 0;
}