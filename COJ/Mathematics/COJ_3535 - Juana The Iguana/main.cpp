#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <algorithm>
#include <vector>
#include <string>
#include <queue>
#include <bitset>
#include <math.h>
#include <map>
#include <cstring>

using namespace std;

typedef long long ll;

/*
    ACCEPTED
*/

bool isprime(ll n){
    if (n==1) return false;
    if (n == 2 || n==3) return true;
    if (n%2==0 || n%3==0) return false;
    long long i = 5, w = 2;
    while (i * i <= n){
        if (n % i == 0) return false;
        i += w;
        w = 6 - w;
    }
    return true;
}


int main()
{
    //ios::sync_with_stdio(0);
    //cin.tie(0);
    int T;
    ll N;
    freopen("input","r", stdin);
    cin >> T;
    while(T--){
        cin >> N;
        cout << (isprime(N-2) ? "yes\n":"no\n");
    }
    return 0;
}

