#include <bits/stdc++.h>
#define MAXN 1000002
using namespace std;

int arr[MAXN];

// ACC

void precalculate(){
    fill(arr, arr+MAXN, 1);
    for (int div=2, i; div <= MAXN/2; div++){
        i = 1;
        while(div * i <= MAXN){
            arr[div * i]++;
            i++;
        }
    }
}

int main() {
    ios::sync_with_stdio(0);
    //cin.tie(0);
    int cases, n, maxDivisors, bestN;
    cin >> cases;
    precalculate();
    while (cases--){
        cin >> n;
        maxDivisors = 0;
        bestN = -1;
        for (int i=1; i<=n; i++){
            if (arr[i] > maxDivisors){
                maxDivisors = arr[i];
                bestN = i;
            }
        }
        cout << bestN << "\n";
    }
    return 0;

}