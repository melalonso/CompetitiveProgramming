#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <vector>
#include <algorithm>

using namespace std;

const int INF = 1 << 30;

/*
int MATRIX[100010][2], n;
int **memo, maxX=0, maxY=0;


int DP(int x, int y){
    if (y==0 || x>maxX) return 0;
    if (memo[x][y]) return memo[x][y];

    int pops = 0, ans = 0;
    for(int i=0; i<n; i++){
        if(x==MATRIX[i][0] && y==MATRIX[i][1]){
            pops = 1;
            break;
        }
    }

    ans = max(pops + DP(x+1,y), pops + DP(x, y-1));

    return memo[x][y] = ans;
}
*/

struct Par
{
    int f, s;
    friend bool operator<(Par a, Par b)
    {
        if (a.s != b.s) return a.s > b.s;
        return a.f < b.f;
    }
};


int main() {
    int cases,x, y,n;
    freopen("input","r",stdin);
    scanf("%d",&cases);
    while(cases--){
        scanf("%d",&n);
        vector<Par> v;
        for(int i=0;i<n;i++){
            scanf("%d %d",&x, &y);
            Par p;
            p.f = x;
            p.s = y;
            v.push_back(p);
        }
        sort(v.begin(), v.end());

        vector<int> lis(n+2, INF);

        vector<int>::iterator it;

        for (int i=0; i<n; i++){
            it = upper_bound(lis.begin(), lis.end(), v[i].f);
            lis[it-lis.begin()] = v[i].f;
        }
        it = upper_bound(lis.begin(), lis.end(), INF-1);
        cout << it-lis.begin() << endl;
    }
    return 0;
}
