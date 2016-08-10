// Imports.

#include <bits/stdc++.h>

using namespace std;



#define MAX 3000000

typedef long long ll;
typedef unsigned long long ull;
typedef pair<int, int> ii;
typedef vector<int> vi;

int n;
vector<int> tri;
int memo[3000002];


int bfs() {
    queue<ii> q;
    q.push({0, 0});
    int sum;
    ii curr;
    while(!q.empty()) {
        curr = q.front(), q.pop();
        cout << "Tengo "<<curr.first<<"\n";
        if (memo[curr.first]) continue;
        memo[curr.first] = curr.second;
        sum = 0;
        for (int i=0; i<tri.size()-1 && sum<=MAX; i++) {
            sum = curr.first + tri[i];
            if (sum>MAX) break;
            if(!memo[sum]) {
                q.push({sum, curr.second+1});
            }
        }
    }
}

//Main

int main() {
    //freopen("input.txt", "r", stdin);
    ios::sync_with_stdio(0);
    //cin.tie(0);
    int curr = 0;
    for(int i = 1; curr < MAX; i++) {
        curr += i;
        tri.push_back(curr);
    }
    memo[1] = 1;
    memo[2] = 2;
    cout << "Antes\n";
    bfs();
    cout << "Despues\n";
    for (int i=0; i<1000; i++) cout << memo[i] << " ";
    while(cin >> n) {
        cout << memo[n] << "\n";
    }

    return 0;
}