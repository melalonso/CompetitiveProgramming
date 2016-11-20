#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <algorithm>
#include <vector>
#include <string>
#include <string.h>
#include <queue>
#include <limits.h>

using namespace std;
typedef long long ll;

/*
    ACCEPTED
    c++11.
*/

string number;
int n; // Length of the string.
ll memo[210];

/*
    Returns long long because the sum does not have to be strictly
    a 32 bit signed integer
    Case -> 5555555666
*/
ll dp(int i) {
    if (i == n) return 0;
    if (memo[i] != -1) return memo[i];
    ll res = 0, num=0;
    for (int j=1; j<=10 && i+j<=n; j++){
        num = stoll(number.substr(i,j));
        if (num <= INT_MAX){
        	res = max(res, num + dp(i+j));
        }
    }
    return memo[i] = res;
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    int N;
    freopen("input", "r", stdin);
    cin >> N;
    while (N--) {
        cin >> number;
        n = number.size();
        memset(memo, -1, sizeof memo);
        cout << dp(0) << "\n";
    }
    return 0;
}
