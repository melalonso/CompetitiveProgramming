#include <iostream>
#include <string.h>
#include <stdio.h>
#include <stdlib.h>

#define MAX 102
using namespace std;

/*
    ACCEPTED.
*/

int ri[]={1,0,-1, 0};
int rj[]={0,1, 0,-1};

int area[MAX][MAX], R, C;;

bool validPos(int i, int j){
    return i<R && i>=0 && j<C && j>=0;
}

int dfs(int i, int j){
    int nexti, nextj, ans = 0;
    for (int k=0; k<4; k++){
        nexti = i+ri[k], nextj=j+rj[k];
        if (validPos(nexti, nextj)){
            if (area[nexti][nextj] < area[i][j] ){
                ans=max(ans, 1+dfs(nexti,nextj));
            }
        }
    }
    return ans;
}

int solve(){
    int maxi = 0, curr;
    for(int i=0;i<R;i++)
        for(int j=0;j<C;j++){
            curr = dfs(i, j);
            if (curr>maxi) maxi = curr;
        }
    return maxi;
}

int main()
{
    int N, x;
    string name;
    freopen("input", "r", stdin);
    cin >> N;
    while(N--){
        cin >> name >> R >> C;

        for(int i=0;i<R;i++)
            for(int j=0;j<C;j++)
                cin >> area[i][j];

        int longest = solve();

        cout << name << ": "<<longest+1<< "\n";
        memset(area, 0, sizeof area);
    }
    return 0;
}
