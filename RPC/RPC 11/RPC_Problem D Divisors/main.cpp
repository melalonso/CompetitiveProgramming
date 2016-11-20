#include <bits/stdc++.h>
using namespace std;

int a, b, c ,d;

bool p(int n){
    return n%a==0 && c%n==0 && n%b && d%n;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    while(cin >> a >> b >> c >> d){
        if (c%a){
            cout << "-1--\n";
            continue;
        }
        int k = c/a;
        int n = c+1;

        for(int i=1; i*i <= k; i++){
            if (k%i==0){
                if (p(a*i)){
                    n = min(n, a*i);
                }
                if(p(a*k/i)){
                    n = min(n, a*k/i);
                }
            }
        }
        if (n<=c) cout << n <<"\n";
        else cout << "-1\n";
    }
    return 0;
}