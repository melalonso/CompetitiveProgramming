#include <iostream>
#include <stdio.h>
#include <math.h>

using namespace std;

const double PI = acos(0)*2.0;

int main()
{
    int cases;
    double r, cirarea, l;
    scanf("%d",&cases);
    while (cases--){
        scanf("%lf",&r);
        cirarea = PI * pow(r,2.0);
        l = sqrt( pow(r+r,2)/2.0 );
        printf("%.2f\n",cirarea - (l*l));
    }
    return 0;
}
