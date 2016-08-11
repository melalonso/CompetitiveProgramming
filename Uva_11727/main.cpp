#include <iostream>
#include <algorithm>
#include <stdio.h>
#include <stdlib.h>

using namespace std;

int main()
{
    int T,caseNo=1;
    scanf("%d",&T);
    int arr[3];
    while (T--){
        scanf("%d %d %d",&arr[0],&arr[1],&arr[2]);
        sort( arr, arr+3);
        printf("Case %d: %d\n",caseNo++,arr[1]);
    }
    return 0;
}
