#include <iostream>
#include <cstring>
#include <stdio.h>
#include <stdlib.h>

using namespace std;

int i, j, M, C, prices[25][25]; // Because it can be up to 20 garments with 20 models.
// Total amount of states for the problem 201 * 20
// 201 prices (0 <= M <=200)
// 20 garments(1 <= C <= 20)


int memo[210][25]; // for top down
bool reachable[25][210]; // for bottom up


// Top down focus.
int shop(int money, int g){
    if (money<0) return -1000000000; // Runs out of money.
    if (g == C) return M - money; // Spent money for a combination.

    if (memo[money][g] != -1) return memo[money][g]; // Memoize - Avoid overlap of states.

    int ans = -1;
    // Backtracking going through every model of every garment.
    for(int model = 1; model <= prices[g][0]; model++)
        ans = max(ans, shop(money - prices[g][model], g + 1)); // Max of every combination.

    return memo[money][g] = ans;
}

// Botton up focus
void shop2(int M){

    for(int model=1; model <= prices[0][0]; model++)
        if (M-prices[0][model]>=0)
            reachable[0][M-prices[0][model]] = true;

    for (int g=1; g < C; g++)
        for(int money =0; money <= M; money++)
            if (reachable[g-1][money]==true)
                for (int model = 1; model<= prices[g][0]; model++)
                    if (money-prices[g][model]>=0)
                        reachable[g][money-prices[g][model]] = true;

    int money;
    for(money = 0; !reachable[C-1][money] && money<=M; money++);

    if (money == M+1) printf("no solution\n");
    else printf("%d\n",M-money);
}


int main()
{
    int cases, score;
    freopen("input", "r", stdin);
    scanf("%d",&cases);
    while(cases--){
        scanf("%d %d",&M, &C);
        for(i=0; i<C; i++){
            scanf("%d",&prices[i][0]);
            for(j=1; j <= prices[i][0]; j++) scanf("%d",&prices[i][j]);
        }
        memset(reachable, false, sizeof reachable);
        shop2(M);
        //if (score < 0) printf("no solution\n");
        //else printf("%d\n",score);
    }
    return 0;
}


