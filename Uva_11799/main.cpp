#include <iostream>
#include <stdio.h>
#include <stdlib.h>

using namespace std;

int main()
{
    int T, N, x, maxx, ind=1;
    freopen("input","r",stdin);
    scanf("%d",&T);
    while(T--){
        maxx = 0;
        scanf("%d",&N);
        while(N--){
            scanf("%d",&x);
            maxx = max(x,maxx);
        }
        printf("Case %d: %d\n",ind++,maxx);
    }
    return 0;
}
