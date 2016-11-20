#include <bits/stdc++.h>

using namespace std;

// ACC

int sumar(int n){
    int res=0;
    while(n){
        res += n%10;
        n /= 10;
    }
    return res;
}

int main() {
    ios::sync_with_stdio(0);
    //cin.tie(0);
    int n, prod, sumN, i;
    while(cin >> n && n){
        sumN = sumar(n);
        for (i=11; i<100000; i++){
            prod = n*i;
            if (sumar(prod) == sumN){
                break;
            }
        }
        cout << i << "\n";
    }
    return 0;
}