#include <iostream>
#include <cmath>
#include <stdio.h>
#include <stdlib.h>

using namespace std;

/*
    ACCEPTED
*/

int main()
{
    long long n, m, res;
    freopen("input", "r", stdin);
    while(scanf("%lld %lld",&n, &m), n||m){
        res = (m-n+1) - (floor(sqrtl(m))-floor(sqrtl(n-1)));
        printf("%lld\n",res);
    }
    return 0;
}
