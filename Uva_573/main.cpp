#include <iostream>
#include <stdio.h>
#include <stdlib.h>

using namespace std;

int main()
{
    int H, D, day, F;
    double climbed, U, fatigue;
    freopen("input","r",stdin);
    while(scanf("%d %lf %d %d",&H ,&U ,&D ,&F) ,H){
        day = 0;
        climbed = 0;
        fatigue = U * (F/100.0);
        while(climbed <= H && climbed>=0){
            if (U > 0) climbed += U;
            if (climbed <= H) climbed -= D;
            U -= fatigue;
            day++;
        }
        climbed > H ? printf("success ") : printf("failure ");
        printf("on day %d\n",day);
    }
    return 0;
}
