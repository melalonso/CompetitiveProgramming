#include <iostream>
#include <bits/stdc++.h>

#define MAX 1000001

using namespace std;

typedef vector<int> vi;
typedef long long ll;

/*
    ACCEPTED
 */

// '+', '-', '*', '/', '%'.
// 0 <= A, B, C <= 9
bool check(int a, int b, int c){
    if (a+b==c || a-b==c || a*b==c) return true;
    if (b) return a/b == c || a%b==c;
    return false;
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    int T, A, B, C;
    cin >> T;
    while(T--){
        cin >> A >> B >> C;
        cout << (check(A, B, C) ? "YES\n" : "NO\n");

    }
    return 0;
}