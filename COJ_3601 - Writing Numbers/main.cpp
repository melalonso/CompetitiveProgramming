#include <bits/stdc++.h>

using namespace std;

string nums[] = {"one", "two", "three", "four", "five", "six", "seven", "eight", "nine", "ten", "eleven", "twelve"};

/*
    ACCEPTED
 */

int main() {
    ios::sync_with_stdio(0);
    //cin.tie(0);
    int k, n;
    cin >> k;
    while (k--) {
        cin >> n;
        cout << nums[n-1] << "\n";
    }
    return 0;
}