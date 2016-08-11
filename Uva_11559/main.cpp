#include <iostream>
#include <stdio.h>
#include <stdlib.h>

#define BN 20000000

using namespace std;

int main()
{
    int N, B, H, W;
    int p, a;
    int minCost;
    freopen("input","r",stdin);
    while(scanf("%d %d %d %d",&N ,&B ,&H ,&W)!= EOF){
        minCost = BN;
        while(H--){
            scanf("%d",&p);
            for(int i=0; i<W; i++){
                scanf("%d",&a);
                if (a >= N && p*N <= B)
                    minCost = min(p*N, minCost);
            }
        }
        minCost==BN ? printf("stay home\n") : printf("%d\n",minCost);
    }
    return 0;
}
