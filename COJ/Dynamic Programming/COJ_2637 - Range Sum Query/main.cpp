#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX 100002
using namespace std;

long long num[MAX];

/*
    ACCEPTED
*/

int main()
{
    int t, n, q, i, j;
    long long x;
    bool flag = false;
    //freopen("input", "r", stdin);
    scanf("%d", &t);
    while(t--){
        getchar();
        memset(num, 0, sizeof num);
        scanf("%d %d", &n, &q);
        scanf("%d", &num[1]);
        flag ? printf("\n"): flag=true;
        for (int i=2; i<=n; i++){
            scanf("%d", &x);
            num[i] = num[i-1] + x;
        }
        while(q--){
            scanf("%d %d", &i, &j);
            if (i>j){
                int tmp = j;
                j = i;
                i = tmp;
            }
            printf("%lld\n", num[j+1]-num[i]);
        }
    }
    return 0;
}
