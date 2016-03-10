#include <iostream>
#include <stdio.h>
#include <stdlib.h>

using namespace std;

/*
    TLE
*/

int main()
{
    int N, res;
    freopen("input", "r", stdin);
    scanf("%d", &N);
    int nums[N];
    for(int i=0; i<N; i++) scanf("%d", &nums[i]);

    for(int i=0; i<N; i++){
        res = 0;
        for(int j=i+1; j<N; j++){
            if (nums[j]>nums[i]) res++;
        }
        i == N-1 ? printf("%d",res) : printf("%d ",res);
    }
    printf("\n");
    return 0;
}
