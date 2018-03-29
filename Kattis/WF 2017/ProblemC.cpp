#include <bits/stdc++.h>
#define MAXV 300

using namespace std;

typedef vector<int> VI;
typedef long long ll;

int LEFT;
int r[MAXV];
bool seen[MAXV];
VI AdjList[MAXV];

bool can_match(int u) {
    for (auto & v : AdjList[u]) {
        if (!seen[v]) {
            seen[v] = true;
            if (r[v] < 0 || can_match(r[v])) {
                r[v] = u;
                return true;
            }
        }
    }
    return false;
}

int max_matching() {
    memset(r, -1, sizeof r);
    int ans = 0;
    for (int u=0 ; u<LEFT ; u++) {
        memset(seen, 0, sizeof seen);
        if (can_match(u)) {
            ans++;
        }
    }
    return ans;
}

void clean() {
    for (auto &i : AdjList) i.clear();
}

int main() {
    ios::sync_with_stdio(false);
    //cin.tie(0);
    int n, m;
    cin >> n >> m;
    vector<vector<int>> board(n, vector<int>(m));
    vector<int> rows(n);
    vector<int> cols(m);
    ll mandatory = 0, totalNeeded = 0, needed;
    ll total = 0, used = 0;
    int x;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cin >> board[i][j];
            rows[i] = max(rows[i], board[i][j]);
            cols[j] = max(cols[j], board[i][j]);
            total += board[i][j];
            used += board[i][j] > 0;
        }
    }

    set<int> S;
    for (int i = 0; i < n; i++) S.insert(rows[i]);
    for (int i = 0; i < m; i++) S.insert(cols[i]);

    S.erase(0);
    S.erase(1);

    for (auto e : S) {
        //cout << "Element "<<e<<" = ";
        vector<int> a, b;
        for (int i = 0; i < rows.size(); i++)
            if (rows[i] == e) a.push_back(i);
        for (int i = 0; i < cols.size(); i++)
            if (cols[i] == e) b.push_back(i);

        clean();
        for (int i : a)
            for (int j : b)
                if (board[i][j])
                    AdjList[i].push_back(100 + j);

        LEFT = 205;
        ll maxMatching = max_matching();
        //cout << maxMatching<<"\n";

        needed = (int) a.size() + (int) b.size() - maxMatching;
        totalNeeded += needed;
        mandatory += (needed * e);
    }

    cout << total - mandatory - (used - totalNeeded) << "\n";
}