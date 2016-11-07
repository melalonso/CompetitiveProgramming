#include <iostream>
#include <math.h>
#include <stdio.h>
#include <stdlib.h>

using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    long long a, b, s1, s2;
    while(scanf("%ld %ld", &a, &b), a || b){
        s1 = ceil((-1 + sqrt(1+8*a)) / 2) - 1;
        s2 = (-1 + sqrt(1+8*b)) / 2;
        printf("%ld\n",s2-s1);
    }
    return 0;
}
