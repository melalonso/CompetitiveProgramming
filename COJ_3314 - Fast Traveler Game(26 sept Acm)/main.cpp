#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <vector>

using namespace std;

int main()
{
    int cases, N, S, D;
    freopen("input","r",stdin);
    scanf("%d",&cases);
    while(cases--){
        scanf("%d %d %d",&N,&S,&D);

        vector< pair<int,int> > player;
        for(int i=1;i<=N;i++) player.push_back(make_pair(i,0));

        vector<int> board(S);
        int p;
        for(int i=0;i<S;i++){
            scanf("%d",&p);
            board[i] = p;
        }

        vector<int> winners;
        int dice, curr_player=0;

        while(D--){
            scanf("%d",&dice);
            player[curr_player].second += dice;
            player[curr_player].second += board[player[curr_player].second];

            if (player[curr_player].second == (S-1)){
                winners.push_back(player[curr_player].first);
                player.erase(player.begin()+curr_player);
                N--;
                if (N>0)curr_player %= N;
                else break;
            }else curr_player = (curr_player+1) % N;
        }

        if (winners.empty()) printf("-1");
        else for(int i=0;i<winners.size();i++) printf("%d ",winners[i]);
        printf("\n");

    }
    return 0;
}
