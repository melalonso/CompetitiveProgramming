#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <algorithm>
#include <vector>
#include <string.h>
#include <queue>
#include <limits.h>

#define MAXN 25
#define INF 9999
using namespace std;

int adjMat[MAXN][MAXN];
int N;

/*
    ACCEPTED
*/

void floydWarshall(){
    for (int k=0; k<N; k++)
        for (int i=0; i<N; i++)
            for (int j=0; j<N; j++)
                adjMat[i][j] = min(adjMat[i][j], adjMat[i][k] + adjMat[k][j]);
}

int solve(){
    int min = INT_MAX, v_total, bestidx;
    for (int i=0; i<N; i++){
        v_total = 0;
        for (int j=0; j<N; j++){
            v_total += adjMat[j][i];
        }
        if (v_total<min) min=v_total, bestidx=i;
    }
    return bestidx;
}

int main()
{
    int M, i, j, k;
    int ncase=1, index;
    freopen("input", "r", stdin);
    freopen("output", "w", stdout);
    while(cin >> N >> M && N!=0){
        memset(adjMat, INF, sizeof adjMat);
        string names[N];
        for (int i=0; i<N; i++){
            cin >> names[i];
            adjMat[i][i] = 0;
        }
        for (int idx=0; idx<M; idx++){
            cin >>i>>j>>k;
            adjMat[i-1][j-1] = k;
            adjMat[j-1][i-1] = k;
        }
        floydWarshall();
        index = solve();
        cout << "Case #"<<ncase++<<" : "<< names[index]<<"\n";
    }
    return 0;
}
