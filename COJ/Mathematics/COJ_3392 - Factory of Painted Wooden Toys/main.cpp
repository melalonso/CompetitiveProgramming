#include <iostream>
#include <bits/stdc++.h>

#define MAX 1000001

using namespace std;

typedef vector<int> vi;
typedef long long ll;

/*
 * ACCEPTED
 */

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    int n;
    while(cin>>n, n){
        cout << (n < 3 ? 0 : 12*(n-2));
        cout << "\n";
    }
    return 0;
}