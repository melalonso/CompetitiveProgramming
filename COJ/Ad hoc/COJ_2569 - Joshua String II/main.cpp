#include <bits/stdc++.h>

using namespace std;

// ACC

int main() {
    ios::sync_with_stdio(0);
    //cin.tie(0);
    int cases, n;
    string str;
    cin >> cases;
    while (cases--) {
        cin >> n;
        priority_queue<string, vector<string>> pq;
        while (n--){
            cin >> str;
            pq.push(str);
        }

        string curr, res = "";
        while (!pq.empty()){
            curr = pq.top(), pq.pop();
            res += curr[0];
            curr.erase(0, 1);
            if (curr.size()) pq.push(curr);
        }
        cout << res << "\n";
    }

    return 0;
}