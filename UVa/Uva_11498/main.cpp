#include <iostream>
#include <stdio.h>
#include <stdlib.h>

using namespace std;

int main()
{
    int k, n, m, x, y;
    //freopen("input","r",stdin);
    while( scanf("%d",&k), k ){
        scanf("%d %d",&n,&m);
        while(k--){
            scanf("%d %d",&x,&y);
            if (x<n && y>m){
                printf("NO");
            }else if (x>n && y>m){
                printf("NE");
            }else if (x<n && y<m){
                printf("SO");
            }else if (x>n && y<m){
                printf("SE");
            }else{
                printf("divisa");
            }
            printf("\n");
        }
    }
    return 0;
}
