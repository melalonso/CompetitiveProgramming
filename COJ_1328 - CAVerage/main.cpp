#include <iostream>
#include <bits/stdc++.h>

#define MAX 1000001

using namespace std;

typedef vector<int> vi;
typedef long long ll;

/*
 * ACCEPTED
 */

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    int T, N, x;
    double total;
    cin >> T;
    while(T--){
        total = 0;
        cin >> N;
        double composite[N];
        fill(composite, composite+N, 0);
        for (int i=0; i < 2; i++) {
            for (int j = 0; j < N; j++) {
                cin >> x;
                composite[j] += x;
                total += x;
            }
        }
        total /= N;

        int res=0;
        for (int j = 0; j < N; j++) if (composite[j] < total) res++;
        cout << res << "\n";
    }
    return 0;
}