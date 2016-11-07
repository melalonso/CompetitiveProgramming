#include <iostream>
#include <stdio.h>
#include <stdlib.h>

#define MAX 52
using namespace std;

/*
    ACCEPTED
    Flood fill
*/

char mapa[MAX][MAX];

int di[] = {-1, 1,  0, 0};
int dj[] = { 0, 0, -1, 1};
int W, H;

int floodfill(int i, int j){
    if (mapa[i][j] == 1) return 0;
    mapa[i][j] = 1; // visited

    for (int k=0; k<4; k++) // Player is in risk -> return
        if (mapa[i+di[k]][j+dj[k]] == 'T')
            return 0;

    int ans = 0;
    char val;
    for (int k=0; k<4; k++){
        val = mapa[i+di[k]][j+dj[k]];
        if (val == '.' || val == 'G'){
            if (val == 'G') ans++;
            ans += floodfill(i+di[k], j+dj[k]);
        }
    }
    return ans;
}

int main()
{
    int bi, bj;
    freopen("input","r",stdin);
    while(scanf("%d %d\n", &W, &H) != EOF){
        for (int i=0; i<H; i++){
            for (int j=0; j<W; j++){
                scanf("%c ", &mapa[i][j]);
                if (mapa[i][j] == 'P') bi = i, bj = j;
            }
        }
        printf("%d\n", floodfill(bi, bj));
    }
    return 0;
}
