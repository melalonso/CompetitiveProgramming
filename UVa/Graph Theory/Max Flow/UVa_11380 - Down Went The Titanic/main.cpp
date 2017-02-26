#include <bits/stdc++.h>

#define MAXV 1902
#define INF INT_MAX

using namespace std;

// ACC

typedef vector<int> vi;

int rows, cols, maxp, vin, vout;
vi graph[MAXV];
char mapa[32][32];
int res[MAXV][MAXV], f, s, t;
vi p;
int mx[] = {-1, 0, 1, 0};
int my[] = {0, 1, 0, -1};

void addEdge(int u, int v) {
    graph[u].push_back(v);
}

// p stores the BFS spanning tree from s
void augment(int v, int minEdge) { // traverse BFS spanning tree from s->t
    if (v == s) {
        f = minEdge;
        return;
    } // record minEdge in a global var f
    else if (p[v] != -1) {
        augment(p[v], min(minEdge, res[p[v]][v]));
        res[p[v]][v] -= f;
        res[v][p[v]] += f;
    }
}

int process() {
    int mf = 0;
    while (1) {
        f = 0;
        vi dist(MAXV, INF);
        dist[s] = 0;
        queue<int> q;
        q.push(s);
        p.assign(MAXV, -1);
        while (!q.empty()) {
            int u = q.front();
            q.pop();
            if (u == t) break; // immediately stop BFS if we already reach sink t
            for (int i = 0; i < graph[u].size(); i++) {
                int v = graph[u][i];
                if (res[u][v] > 0 && dist[v] == INF)
                    dist[v] = dist[u] + 1, q.push(v), p[v] = u;
            }
        }
        augment(t, INF);
        if (f == 0) break; // we cannot send any more flow (f = 0), terminate
        mf += f; // we can still send a flow, increase the max flow!
    }

    return mf;
}

bool valid(int x, int y) {
    return x >= 0 && x < rows && y >= 0 && y < cols;
}

int toInt(int x, int y) {
    return (cols * (x + 1)) - (cols - (y + 1));
}

void connect(int x, int y) {

    int weight = INF;
    vin = toInt(x, y);
    vout = vin + 900;
    addEdge(vin, vout), addEdge(vout, vin);

    if (mapa[x][y] == '*') {
        res[s][vin] = 1, weight = 1;
        addEdge(s, vin); // Multi-source
    } else if (mapa[x][y] == '#') {
        res[vout][t] = maxp;
        graph[vout].push_back(t); // Multi-sink
    } else if (mapa[x][y] == '.') weight = 1;

    res[vin][vout] = weight; // sets amount of uses of vertex

    for (int i = 0; i < 4; i++) {
        int nx = x + mx[i];
        int ny = y + my[i];
        if (valid(nx, ny) && mapa[nx][ny] != '~') {
            int neighbor = toInt(nx, ny);
            graph[vout].push_back(neighbor);
            graph[neighbor].push_back(vout);
            res[vout][neighbor] = INF;
        }
    }

}

void clean() {
    for (int i = 0; i < MAXV; i++) {
        graph[i].clear();
        for (int j = 0; j < MAXV; j++)
            res[i][j] = 0;
    }
}

int main() {
    ios::sync_with_stdio(0);
    //cin.tie(0);
    freopen("input", "r", stdin);
    string line;
    s = 0, t = 1900;
    while (cin >> rows >> cols >> maxp) {
        // cout << "Rows="<<rows<<", cols="<<cols<<"\n";
        for (int i = 0; i < rows; i++) cin >> mapa[i];

        for (int i = 0; i < rows; i++)
            for (int j = 0; j < cols; j++)
                if (mapa[i][j] != '~') connect(i, j);

        cout << process() << "\n";

        clean();
        getline(cin, line);
    }

    return 0;
}
