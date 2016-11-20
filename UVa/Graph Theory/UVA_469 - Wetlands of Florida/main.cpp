#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX 101
using namespace std;

/*
    ACCEPTED
    Flood fill
*/

char mapa[MAX][MAX];
char visited[MAX][MAX];

int di[] = {-1, 1,  0, 0, -1, -1,  1, 1};
int dj[] = { 0, 0, -1, 1, -1,  1, -1, 1};
int n, m;

int floodfill(int i, int j){
    if (i<0 || i>=n || j<0 || j>=m) return 0;
    visited[i][j] = 1; // visited
    int ans = 1;
    for (int k=0; k<8; k++){
        if (mapa[i+di[k]][j+dj[k]] == 'W' && !visited[i+di[k]][j+dj[k]]){
            ans += floodfill(i+di[k], j+dj[k]);
        }
    }
    return ans;
}

int main()
{
    int cases;
    bool flag = false;
    freopen("input","r",stdin);
    scanf("%d\n\n", &cases);
    while(cases--){
        char inp[MAX];
        if (flag) printf ("\n"); flag = true;
        n = 0;
        while ( gets (inp) && strlen (inp) > 0 ) {
            if ( inp [0] == 'L' || inp [0] == 'W' ) {
                strcpy (mapa[n], inp);
                m = strlen (inp);
                n++;
            }else {
                int r, c;
                memset(visited, 0, sizeof visited);
                sscanf(inp, "%d %d", &r, &c);
                printf ("%d\n", floodfill(r-1, c-1));
            }
        }

    }
    return 0;
}

