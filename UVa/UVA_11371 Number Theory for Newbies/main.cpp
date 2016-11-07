#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <algorithm>
#include <vector>
#include <string.h>
#include <string>

using namespace std;

long long stoll(string s, int len) {
    long long res = 0;
    for(int i=0; i<len; i++)
        res = res * 10 + s[i] - 48;
    return res;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie();
    string s;
    long long n, m;
    freopen("input", "r", stdin);
    while (cin >> s) {
        int len = s.length();
        sort(s.rbegin(), s.rend());
        n = stoll(s,len);
        sort(s.begin(), s.end());
        int k = 0;
        while (k < len && s[k] == '0') k++;
        if (k < len) swap(s[0], s[k]);
        m = stoll(s,len);
        printf("%lld - %lld = %lld = 9 * %lld\n", n, m, n - m, (n - m) / 9);
    }
}
