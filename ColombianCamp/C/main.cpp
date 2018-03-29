#include <bits/stdc++.h>

using namespace std;
#define forr(i, a, b) for(int i=(a); i<(b); i++)
#define forn(i, n) forr(i,0,n)
#define sz(c) ((int)c.size())
#define zero(v) memset(v, 0, sizeof(v))
#define dforn(i, n) for(int i=n-1; i>=0; i--)

priority_queue<int> pq;

int Q;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int type, e;
    stack<int> stack1;
    cin >> Q;
    int maxx = 0;
    forn(i, Q) {
        cin >> type;
        if (type == 1) {
            cin >> e;
            maxx = max(stack1.size() ? stack1.top() : 0, e);
            stack1.push(maxx);
        } else if (type == 2) {
            stack1.pop();
        } else {
            cout << stack1.top() << "\n";
        }
    }
    return 0;
}
