#include <bits/stdc++.h>
#define MAXN 1000002

using namespace std;

// ACC

string P, T;
int b[MAXN], n;

void kmpPreprocess() {
    int i = 0, j = -1;
    b[0] = -1;
    while (i < n) {
        while (j >= 0 && P[i] != P[j]) j = b[j];
        i++, j++;
        b[i] = j;
    }
}



int main() {
    ios::sync_with_stdio(0);
    //cin.tie(0);
    cin >> P;
    n = (int) P.size();
    kmpPreprocess();

    //for (int i=0; i<=n; i++) cout << b[i] << " ";
    //cout << "\n";

    int matches = b[n];
    if (!matches){
        cout << "Just a legend\n";
    }else{
        int max = 0;
        bool flag = false;
        for (int i = n-1; i >= matches; i--){
            if (b[i] >= matches){
                flag = true;
                max = matches;
                break;
            }
        }
        if (!flag) max = b[matches];
        if (!max) cout << "Just a legend\n";
        else cout << P.substr(0, max) << "\n";
    }

    return 0;
}