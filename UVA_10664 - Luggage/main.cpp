#include <iostream>
#include <iomanip>
#include <string>
#include <sstream>
#include <string.h>
#include <stdlib.h>
#include <stdio.h>

#define MAXN 25
using namespace std;

/*
    ACCEPTED
*/

int memo[MAXN][205];
int target, n;
int weight[MAXN];

int DP(int i, int sum){
    if (sum == target) return 1;
    if (i==n || sum>target) return 0;
    if (memo[i][sum] != -1) return memo[i][sum];
    memo[i][sum] = DP(i+1, sum) + DP(i+1, sum + weight[i]);
    return memo[i][sum];
}

int main()
{
    int m, totalsum;
    freopen("input", "r", stdin);
    cin >> m;
    string str;
    getline(cin, str);
    while(m--){
        totalsum = n = 0;
        getline(cin, str);
        istringstream ss(str);
        int num;
        while(ss >> num){
            weight[n] = num;
            totalsum += num;
            n++;
        }
        if (totalsum%2) cout << "NO\n";
        else{
            target = totalsum/2;
            memset(memo, -1, sizeof memo);
            if (DP(0, 0)) cout << "YES\n";
            else cout << "NO\n";
        }
    }
    return 0;
}
