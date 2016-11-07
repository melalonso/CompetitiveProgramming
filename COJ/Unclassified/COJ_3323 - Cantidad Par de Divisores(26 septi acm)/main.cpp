#include <iostream>
#include <cmath>
#include <stdio.h>

using namespace std;

int main()
{
    unsigned long long n, m, res;
    //freopen("input","r",stdin);
    while(scanf("%llu %llu",&n,&m),n||m){
        res = (m-n+1) - (floor(sqrt(m)) - floor(sqrt(n)));
        if ( sqrt(n)==floor(sqrt(n)) ) res--;
        printf("%llu\n",res);
    }
    return 0;
}
