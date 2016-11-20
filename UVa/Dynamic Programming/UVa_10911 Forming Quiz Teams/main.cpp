#include <iostream>
#include <bits/stdc++.h>

#define MAX 9

using namespace std;

typedef vector<int> vi;
typedef long long ll;
typedef pair<int,int> pii;
typedef vector<pii> vii;

int N, target;
double dist[2*MAX][2*MAX];
double memo[(1<<(2*MAX))];

/*
 * ACCEPTED
 */

double DP(int bitmask) {
    if (memo[bitmask] > -0.5) return memo[bitmask];
    if (bitmask == target){
        return memo[bitmask] = 0;
    }

    int p1;
    for (p1 = 0; p1 < 2*N; p1++) // find first point
        if (!(bitmask&(1<<p1))) break;

    double ans = 1000000000.0;
    for (int p2 = p1+1; p2 < 2*N; p2++){ // find second point
        if ( !(bitmask&(1<<p2)) ){
            ans = min(ans, dist[p1][p2] + DP( bitmask | (1<<p1) | (1<<p2) ) );
        }
    }
    return memo[bitmask] = ans;
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    int x, y, index=1;
    vii points;
    freopen("input", "r", stdin);
    freopen("output", "w", stdout);
    while(cin >> N, N){
        points.clear();
        for (int i=0; i<2*N; i++){
            cin.ignore(20,' ');
            cin >> x >> y;
            points.push_back(make_pair(x,y));
        }

        for (int i=0; i<2*N; i++){
            for (int j=i+1; j<2*N; j++){
                dist[i][j] = hypot(points[i].first-points[j].first, points[i].second-points[j].second);
            }
        }

        target = (1<<(2*N))-1;
        fill(memo, memo+(1<<(2*MAX)), -1.0);

        double res = DP(0);
        cout << "Case "<<index<<": ";
        cout << fixed << setprecision(2) <<res << "\n";
        index++;
    }

    return 0;
}