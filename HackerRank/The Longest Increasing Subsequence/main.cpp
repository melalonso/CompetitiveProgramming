#include <iostream>
#include <vector>


using namespace std;

// ACC

int n, x;
vector<int> v;

int CeilIndex(vector<int> &v, int l, int r, int key) {
    while (r-l > 1) {
        int m = l + (r-l)/2;
        if (v[m] >= key) r = m;
        else l = m;
    }
    return r;
}

int LIS() {
    vector<int> tail(n);
    int length = 1;

    tail[0] = v[0];
    for (int i = 1; i < n; i++) {
        if (v[i] < tail[0]) tail[0] = v[i];
        else if (v[i] > tail[length-1]) tail[length++] = v[i];
        else tail[CeilIndex(tail, -1, length-1, v[i])] = v[i];
    }

    return length;
}

int main() {
    ios::sync_with_stdio(0);
    //cin.tie(0);
    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> x;
        v.push_back(x);
    }
    cout << LIS() << "\n";
    return 0;
}
