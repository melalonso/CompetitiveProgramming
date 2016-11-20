#include <bits/stdc++.h>

using namespace std;
typedef pair<int, vector<int>> pii;

vector<int> initial(8), final(8);
// This shit is awesome, first time I use one xD
priority_queue<pii, vector<pii>, greater<pii>> pq;
// Cool, to mark boards as visited
set<vector<int>> visitedSet;

// #ILoveDijkstra
int dijkstra() {
    // Push first board to priority queue
    pq.push({0, initial});
    while (true) {
        int cost;
        vector<int> curr;
        // Tie is from tuple. Cool trick btw
        tie(cost, curr) = pq.top();
        pq.pop();

        // If I have already stayed in this board, just skip it
        if (visitedSet.find(curr) != visitedSet.end()) continue;
        // In case we reach the goal... (We can compare vectors just by using ==)
        if (curr == final) return cost;

        // Mark as visited
        visitedSet.insert(curr);

        // Swap adjacent containers in the same row
        for (int i = 0; i < 8; i++) {
            if (i % 4 != 3) {
                swap(curr[i], curr[i + 1]);
                if (visitedSet.find(curr) == visitedSet.end()) {
                    // Push with the new cost, according the weight of the containers swapped.
                    pq.push({cost + curr[i] + curr[i + 1], curr});
                }
                swap(curr[i], curr[i + 1]);
            }
        }

        // Swap adjacent containers in the same column
        for (int i = 0; i < 4; i++) {
            swap(curr[i], curr[i + 4]);
            if (visitedSet.find(curr) == visitedSet.end()) {
                // Push with the new cost, according the weight of the containers swapped.
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
        // Read the boards as a vector.
        for (int i = 1; i < 8; i++) cin >> initial[i];
        for (int i = 0; i < 8; i++) cin >> final[i];

        // Magic part
        cout << dijkstra() << "\n";

        // Clean the priority queue
        while (!pq.empty()) pq.pop();
        // Clean the set
        visitedSet.clear();
    }

    return 0;
}