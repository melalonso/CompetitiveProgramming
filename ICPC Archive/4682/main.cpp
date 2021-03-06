#include <bits/stdc++.h>

#define MAXN 3500000
#define ALPH 2
using namespace std;

int trie1[MAXN][ALPH], cnt;

void insert(string word) {
    //cout << "inserting "<<word<<"\n";
    int node = 0;
    for (int i = 0; i < word.size(); i++) {
        int letter = word[i] - '0';
        if (trie1[node][letter] == 0) {
            trie1[node][letter] = ++cnt;
            //cout << letter << " en nodo "<<node<<" apunta a "<<trie1[node][letter]<<"\n";
        }
        node = trie1[node][letter];
    }
}

int getMaxXor(string word) {
    string maxXor = "";
    int node = 0;
    for (int i = 0; i < word.size(); i++) {
        int letter = word[i] - '0';
        //cout << "Letra es "<<letter;
        if (trie1[node][!letter]) {
            //cout << " y Tenia inverso";
            maxXor.append("1");
            node = trie1[node][!letter];
        } else {
            maxXor.append("0");
            node = trie1[node][letter];
        }
    }
    bitset<32> bs(maxXor);
    //cout << "desde " << word << " salio " << maxXor << "\n";
    int xxor = bs.to_ulong();;
    return xxor;
}

/*
3
7 8 5

2 5 3 7 7 7 0 5 3 8 2 6 4

*/
int main() {
    ios::sync_with_stdio(0);
    //cin.tie(0);
    int n, a, res, pre, cases;

    cin >> cases;
    while (cases--) {
        res = pre = cnt = 0;

        memset(trie1, 0, sizeof trie1);
        bitset<32> bs(0);
        insert(bs.to_string());

        cin >> n;
        for (int i = 0; i < n; i++) {
            cin >> a;
            pre = pre ^ a;
            bs = bitset<32>(pre);
            insert(bs.to_string());

            //cout << "Xor es " << xorRes << "\n";
            res = max(res, getMaxXor(bs.to_string()));

        }
        cout << res << "\n";
    }

    return 0;
}