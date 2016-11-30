#include <bits/stdc++.h>

using namespace std;

// ACC

int main() {
    int n, k;
    cin >> n >> k;
    string arr;
    cin >> arr;
    stack<int> s;
    for (int i = 0; i < n; i++) {
        while (!s.empty() && arr[i] - '0' > s.top() && (s.size() + n - i - 1) >= n-k) {
            s.pop();
        }
        if (s.size() < n - k) s.push(arr[i] - '0');
    }

    string res = "";
    for (int i=0; i<n-k; i++){
        res = to_string(s.top()) + res;
        s.pop();
    }
    cout << res << "\n";
    return 0;
}