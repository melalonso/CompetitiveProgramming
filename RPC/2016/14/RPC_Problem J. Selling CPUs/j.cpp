#include <bits/stdc++.h>

#define PI 3.14159265358979323846
#define E 2.71828182845904523536
#define MOD 1000000007
#define EPSILON 0.000000001
#define MAX_INT 2147483647
#define MIN_INT -2147483648
#define MAX_N 100001

using namespace std;

typedef long long ll;
typedef vector<int> vi;

int c, m;
int memo[101][101][101];

int prices[101][101];

int dp(int i, int j, int cpu) {

    if (i >= m) return 0;

    if (j >= c) {
        if (i < m-1 && cpu) {
            i++;
            j = 0;
            if(memo[i][j][cpu] != -1) return memo[i][j][cpu];
            else return memo[i][j][cpu] = dp(i, j, cpu);
        } else {
            return 0;
        }

    }

    if(memo[i][j][cpu] != -1) return memo[i][j][cpu];

    int res;
    if (cpu - (j+1) >= 0) {
        res = max(prices[i][j] + dp(i+1, 0, cpu-(j+1)), dp(i, j+1, cpu));
    } else {
        res = dp(i, j+1, cpu);
    }
    return memo[i][j][cpu] = res;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    while(cin >> c >> m) {
        for(int i = 0; i < m; i++) {
            for(int j = 0; j < c; j++) {
                cin >> prices[i][j];
            }
        }

        memset(memo, -1, sizeof memo);

        cout << dp(0, 0, c) << "\n";
    }

}