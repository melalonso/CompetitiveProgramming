#include <bits/stdc++.h>

#define forr(i, a, b) for(int i=(a); i<(b); i++)
#define forn(i, n) forr(i,0,n)
#define sz(c) ((int)c.size())
#define zero(v) memset(v, 0, sizeof(v))
#define dforn(i, n) for(int i=n-1; i>=0; i--)
#define MAXN 105

using namespace std;


int mapa[MAXN][MAXN], N;
bool visited[MAXN][MAXN];
int dr[] = {1, 0, -1, 0};
int dl[] = {0, 1, 0, -1};

int dfs(int i, int j, int c1, int c2) {
    if (i < 0 || i >= N || j < 0 || j >= N) return 0;
    visited[i][j] = true;
    mapa[i][j] = c2;
    int ans = 1;
    for (int k = 0; k < 4; k++) {
        if (!visited[i + dr[k]][j + dl[k]]) {
            ans += dfs(i + dr[k], j + dl[k], c1, c2);
        }
    }
    return ans;
}

void clear() {
    forn(i, MAXN)forn(j, MAXN)visited[i][j] = false;
}

int main() {
    ios::sync_with_stdio(false);
    //cin.tie(0);
    string line;
    int val1, val2;
    while (cin >> N && N) {
        clear();
        getline(cin, line);
        memset(mapa, 0, sizeof mapa);
        int group = 1;
        forn(i, N - 1) {
            getline(cin, line);
            stringstream s(line);
            while (s >> val1) {
                s >> val2;
                mapa[val1-1][val2-1] = group;
            }
            group++;
        }

        vector<int> mygroups;
        forn(i, N) {
            forn(j, N) {
                if (!visited[i][j]){
                    int res = dfs(i, j, mapa[i][j], -1);
                    cout << "hay "<<res <<" de "<<mapa[i][j]<<"\n";
                    mygroups.push_back(res);
                }
            }
        }

        if (mygroups.size() == N){
            bool flag = true;
            forn(i, N){
                if (mygroups[i] != N){
                    flag = false;
                    break;
                }
            }

            cout << (flag ? "good\n" : "wrong\n");

        }else {
            cout << "wrong\n";
        }

    }
    return 0;
}
