#include <bits/stdc++.h>

#define forr(i, a, b) for(int i=(a); i<(b); i++)
#define forn(i, n) forr(i,0,n)
#define sz(c) ((int)c.size())
#define zero(v) memset(v, 0, sizeof(v))
#define dforn(i, n) for(int i=n-1; i>=0; i--)
#define forall(it,v) for(auto it=v.begin(); it!=v.end;++it)

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(false);
    int W, P, x;
    cin >> W >> P;
    vector<int> partitions;
    partitions.push_back(0);
    partitions.push_back(W);
    forn (i, P) {
        cin >> x;
        partitions.push_back(x);
    }
    sort(partitions.begin(), partitions.end());
    set<int> results;
    forn(i, P + 2) {
        forr(j, i + 1, P + 2) {
            results.insert(partitions[j] - partitions[i]);
        }
    }
    int i = 0;
    set<int>::iterator it;
    for (it = results.begin(); it != results.end(); it++) {
        cout << *it;
        if (i < results.size() - 1) cout << " ";
        i++;
    }

    return 0;
}