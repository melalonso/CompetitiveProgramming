#include <bits/stdc++.h>

using namespace std;

// ACC

vector<int> weight;
vector<int> desire;
int n, m;
int memo[2][12900];

int knapsack(){
    memset(memo[0], 0, sizeof memo[0]);
    for(int i = 1; i <= n; i++) {
        int *cur = memo[i&1], *prev = memo[!(i&1)]; // Alternate rows
        for(int j = 0; j <= m; j++) {
            if (j >= weight[i-1])
                cur[j] = max(prev[j], desire[i-1] + prev[j-weight[i-1]] );
            else
                cur[j] = prev[j];
        }
    }
    return memo[n&1][m];
}


int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> n >> m;
    weight.resize(n+5);
    desire.resize(n+5);
    for(int i=0; i<n; i++){
        cin >> weight[i] >> desire[i];
    }
    cout << knapsack() << "\n";
    return 0;
}