#include <bits/stdc++.h>

using namespace std;

// ACC

int main() {
    ios::sync_with_stdio(0);
    //cin.tie(0);
    int n;
    cin >> n;
    string fn, ln;
    vector<pair<string, string>> names;
    for (int i=0; i<n; i++){
        cin >> fn >> ln;
        names.push_back({ln, fn});
    }
    sort(names.begin(), names.end());
    for (int i=0; i<n; i++){
        cout << names[i].second <<" "<< names[i].first << "\n";
    }
    return 0;
}