#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

#define MAX 102
using namespace std;

/*
    ACCEPTED
    Used the trick for reading a sequence of char.

    Could be improved cleaning the i,j space after looking at it (assigning 's' to it)
    this way there's no need to use the visited array and clean function.
*/

bool visited[MAX][MAX];
char mapa[MAX][MAX];
int length;

void clean(){
    for (int i=0; i<MAX; i++)
        for (int j=0; j<MAX; j++){
            visited[i][j] = false;
            mapa[i][j] = NULL;
        }
}

void print(){
    for (int i=0; i<MAX; i++){
        for (int j=0; j<MAX; j++)
            printf("%c ",mapa[i][j]);
        printf("\n");
    }
}

// 8 neighbors of a position.
int ni[] = {-1, 1,  0, 0, -1, 1, -1,  1};
int nj[] = { 0, 0, -1, 1, -1, 1,  1, -1};

int DFS(int x, int y){
    int k, l;
    visited[x][y] = true;
    for(int i=0; i<8; i++){
        k = x+ni[i], l = y+nj[i];
        if (mapa[k][l]=='l' && !visited[k][l]){
            ++length;
            DFS(k, l);
        }
    }
    return length;
}

int main()
{
    int n, total, biggest, smallest;
    //freopen("input","r",stdin);
    while(scanf("%d",&n),n){
        total = biggest = 0;
        smallest = INT_MAX;
        clean();
        for (int i=0; i<n; i++)
            scanf("%s",mapa[i+1]+1);

        //print();
        for (int i=1; i<=n; i++)
            for (int j=1; j<=n; j++){
                if (!visited[i][j] && mapa[i][j]=='l'){
                    length = 1;
                    int len = DFS(i, j);
                    if (len>biggest) biggest = len;
                    if (len<smallest) smallest = len;
                    total++;
                }
            }

        if (total) printf("%d %d %d\n",total, smallest, biggest);
        else printf("0 0 0\n");

    }
    return 0;
}
