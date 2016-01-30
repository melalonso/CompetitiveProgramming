#include <iostream>
#include <stdio.h>
#include <stdlib.h>

using namespace std;

/*
    ACCEPTED
    but could be improved checking it every position has a - neighbor and cnt++
    another improvement is read the whole line with scanf("%s",arr[i])
*/

char **island;
// 3 <= n, m <= 1000

int getneigh(int i, int j){
    int res = 0;
    if(island[i-1][j]=='+') res++;
    if(island[i+1][j]=='+') res++;
    if(island[i][j-1]=='+') res++;
    if(island[i][j+1]=='+') res++;
    return res;
}

int main()
{
    int n, m, neigh, inside=0, validblock=0;
    freopen("input","r",stdin);
    scanf("%d %d\n",&n, &m);
    island = new char*[n];
    for (int i=0; i<n; i++) island[i] = new char[m];

    for (int i=0; i<n; i++)
        for (int j=0; j<m; j++)
            scanf(" %c",&island[i][j]);

    for (int i=1; i<n-1;i++){
        for (int j=1; j<m-1;j++){
            if (island[i][j]=='+'){
                validblock++;
                neigh = getneigh(i ,j);
                if (neigh==4) inside++;
            }
        }
    }
    printf("%d\n",validblock-inside);
    return 0;
}
