#include <iostream>
#include <stdio.h>
#include <cmath>

using namespace std;

const double eps=1e-6;

/*
    ACCEPTED
*/

int main()
{
    int T, A, N, idx=1;
    scanf("%d",&T);
    double area;
    while(T--){
        scanf("%d %d",&A, &N);
        area = A*A;
        if (N!=1) area = area / pow(2.0, N-1);
        printf("Case #%d: %.2lf\n",idx, area+eps);
        idx++;
    }
    return 0;
}
