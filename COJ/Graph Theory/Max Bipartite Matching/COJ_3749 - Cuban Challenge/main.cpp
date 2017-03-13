#include <bits/stdc++.h>
#define MAXV 20010

using namespace std;

// ACC

int mx[4] = {-1, 0, 1, 0};
int my[4] = {0, 1, 0, -1};
char board[22][1002];
int n, m;
typedef vector<int> VI;

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

int toInt2(int i, int j){
    if (m%2 && i%2){
        return (i*m/2) + (j/2) + (j%2);
    }
    return (i*m/2) + (j/2);
}

bool isValid(int x, int y) {
    return x >= 0 && x < n && y >= 0 && y < m;
}

int process() {
    int total = 0, xneigh, yneigh;

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (board[i][j] == '.') {
                total++;
                if ((i + j) % 2) {
                    for (int k = 0; k < 4; k++) {
                        xneigh = i + mx[k];
                        yneigh = j + my[k];
                        if (isValid(xneigh, yneigh) && board[xneigh][yneigh] == '.') {
                            int from = toInt2(i, j);
                            int to = toInt2(xneigh, yneigh);
                            AdjList[from].push_back(to);
                        }
                    }
                }
            }
        }
    }

    int maxPairs = max_matching();
    return ((total - (2 * maxPairs)) + 1) / 2;
}

int main() {

    ios::sync_with_stdio(0);
    cin.tie(0);
    int idx = 1;
    while (cin >> n >> m && (n || m)) {
        LEFT = ((n*m)/2) + 10;
        for (int i = 0; i < n; i++)
            for (int j = 0; j < m; j++)
                cin >> board[i][j];

        cout << "Case #" << idx << ": " << process() << "\n";
        idx++;

        for (int i=0; i<MAXV; i++) AdjList[i].clear();
    }

    return 0;
}

