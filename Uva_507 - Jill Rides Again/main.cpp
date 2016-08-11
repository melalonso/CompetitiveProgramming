#include <iostream>
#include <stdio.h>
#include <stdlib.h>

using namespace std;



int main()
{
    int cases, n;
    freopen("input","r",stdin);
    scanf("%d",&cases);
    for(int rn = 1; rn <= cases; rn++){
        scanf("\n%d",&n);
        int vals[n-1];
        for(int i=0;i<n-1;i++)
            scanf("%d",&vals[i]);

        int max = 0, sum = 0;

        int ini = n-3, fin = n-2;
        int prevFin = 0, prevIni =0;

        for(int i=(n-2); i>=0; i--){
            sum += vals[i];
            if ( sum > max ){
                max = sum;
                prevIni = ini;
                ini = i+2;
            }else if (sum == max){
                if (prevFin-prevIni > (i+2)-ini){
                    ini = prevIni;
                    fin = prevFin;
                }
            }

            if (sum<0){
                prevFin = fin;
                fin = i+2;
                sum = 0;
            }
        }
        if (!max) printf("Route %d has no nice parts\n",rn);
        else printf("The nicest part of route %d is between stops %d and %d\n",rn, ini, fin);
    }
    return 0;
}
