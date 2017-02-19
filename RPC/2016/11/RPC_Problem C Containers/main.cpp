#include <bits/stdc++.h>

using namespace std;
typedef pair<int, vector<int>> pii;

vector<int> initial(8), final(8);
priority_queue<pii, vector<pii>, greater<pii>> pq;
set<vector<int>> visitedSet;

int dijkstra() {
    pq.push({0, initial});
    vector<int> curr;
    int cost;
    while (true) {
        tie(cost, curr) = pq.top(), pq.pop();
        
        if (visitedSet.find(curr) != visitedSet.end()) continue;
        
        if (curr == final) return cost;

        visitedSet.insert(curr);

        // Swap adjacent containers in the same row
        for (int i = 0; i < 8; i++) {
            if (i % 4 != 3) {
                swap(curr[i], curr[i + 1]);
                if (visitedSet.find(curr) == visitedSet.end()) {
                    pq.push({cost + curr[i] + curr[i + 1], curr});
                }
                swap(curr[i], curr[i + 1]);
            }
        }

        // Swap adjacent containers in the same column
        for (int i = 0; i < 4; i++) {
            swap(curr[i], curr[i + 4]);
            if (visitedSet.find(curr) == visitedSet.end()) {
                pq.push({cost + curr[i] + curr[i + 4], curr});
            }
            swap(curr[i], curr[i + 4]);
        }
    }
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    while (cin >> initial[0]) {

        for (int i = 1; i < 8; i++) cin >> initial[i];
        for (int i = 0; i < 8; i++) cin >> final[i];

        cout << dijkstra() << "\n";


        while (!pq.empty()) pq.pop();
        visitedSet.clear();
    }

    return 0;
}
