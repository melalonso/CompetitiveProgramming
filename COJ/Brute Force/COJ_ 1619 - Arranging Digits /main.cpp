#include <bits/stdc++.h>

using namespace std;

// ACC
vector<int> res;

void getDiff(vector<string> v) {
    int maxx = -1, minn = INT32_MAX;
    int num;
    for (int i = 0; i < v.size(); i++) {
        num = stoi(v[i]);
        maxx = max(maxx, num);
        minn = min(minn, num);
    }
    res.push_back(maxx-minn);
}

void permute(vector<string> vs, int l, int r) {
    if (l == r) {
        getDiff(vs);
    } else {
        for (int i = l; i < r; i++) {
            for (int j = 0; j < vs.size(); j++) {
                swap(vs[j][l], vs[j][i]);
            }
            permute(vs, l + 1, r);
            for (int j = 0; j < vs.size(); j++) {
                swap(vs[j][l], vs[j][i]);
            }
        }
    }
}


// 1 <= n, k <= 8
int main() {
    ios::sync_with_stdio(0);
    //cin.tie(0);
    int n, k;
    string s;
    cin >> n >> k;
    vector<string> vec;
    for (int i = 0; i < n; i++) {
        cin >> s;
        vec.push_back(s);
    }
    permute(vec, 0, k);
    cout << *min_element(res.begin(), res.end());
    return 0;
}