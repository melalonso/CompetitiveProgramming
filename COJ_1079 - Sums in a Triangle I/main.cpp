#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

using namespace std;

int l, **arr;

int DP(){
    for (int i=l-2; i>=0; i--)
        for (int j=0; j<=i; j++)
            arr[i][j] = max(arr[i][j] + arr[i+1][j], arr[i][j] + arr[i+1][j+1]);
    return arr[0][0];
}

int main()
{
    int cases;
    //freopen("input","r",stdin);
    scanf("%d",&cases);
    while (cases--){
        scanf("%d",&l);
        arr = new int*[l];
        for (int i=0; i<l; i++) arr[i] = new int[l];

        for (int i=0; i<l; i++)
            for (int j=0; j<=i; j++)
                scanf("%d",&arr[i][j]);

        int res = DP();
        printf("%d\n",res);
    }
    return 0;
}
