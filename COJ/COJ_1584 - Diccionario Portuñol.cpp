#include <bits/stdc++.h>

#define MAXN 100002
#define ALPH 26
using namespace std;

typedef long long ll;
int P, S, cnt, cnt2;
bool start1[ALPH];
int trie1[MAXN][ALPH], trie2[MAXN][ALPH], suffix[ALPH];

void addPrefix(int node, string word) {
    for (int i = 0; i < word.size(); i++) {
        int letter = word[i] - 'a';
        if (trie1[node][letter] == 0) {
            trie1[node][letter] = cnt++;
        }
        node = trie1[node][letter];
    }
}

void addSuffix(int node, string word) {
    int len = word.size();
    int letter = word[len - 1] - 'a';
    start1[letter] = true;
    for (int i = len - 1; i >= 0; i--) {
        letter = word[i] - 'a';
        if (trie2[node][letter] == 0) {
            trie2[node][letter] = cnt2++;
            ++suffix[letter];
        }
        node = trie2[node][letter];
    }
}

ll ans = 0;

void dfs(int node) {
    for (int i = 0; i < ALPH; i++) {
        if (trie1[node][i]) { // follow prefix
            dfs(trie1[node][i]);
            if (node > 0 && start1[i]) ans++;
        } else if (node > 0) {
            ans += suffix[i];
        }
    }
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    string s;
    while (cin >> P >> S, P || S) {

        cnt = 1;
        for (int i = 0; i < P; i++) {
            cin >> s, addPrefix(0, s);
        }

        cnt2 = 1;
        for (int i = 0; i < S; i++) {
            cin >> s, addSuffix(0, s);
        }

        ans  = 0, dfs(0);
        cout << ans << "\n";

        memset(trie1, 0, sizeof trie1);
        memset(trie2, 0, sizeof trie2);
        memset(suffix, 0, sizeof suffix);
        memset(start1, false, sizeof start1);
    }
    return 0;
}
