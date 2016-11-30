#include <bits/stdc++.h>

using namespace std;

/*
 * ACC
 */

vector<int> getDivisors(int n) {
    vector<int> res;
    res.push_back(1);
    for (int i = 2; i <= sqrt(n); i++) {
        if (n % i == 0) {
            res.push_back(i);
            if (n / i != i) res.push_back(n / i);
        }
    }
    return res;
}

int main() {
    int n;
    while (cin >> n && n != -1) {
        vector<int> divisors = getDivisors(n);
        int sum = std::accumulate(divisors.begin(), divisors.end(), 0);
        if (sum==n){
            cout << n << " = ";
            sort(divisors.begin(), divisors.end());
            for (int i=0; i<divisors.size(); i++){
                cout << divisors[i];
                if (i+1<divisors.size())  cout << " + ";
            }
        }else{
            cout << n << " is NOT perfect.";
        }
        cout << "\n";
    }
    return 0;
}