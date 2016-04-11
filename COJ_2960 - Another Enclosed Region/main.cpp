#include <iostream>
#include <bits/stdc++.h>

using namespace std;

/*
    ACCEPTED
 */

int er[] = {1,2,0,1,0,0,0,0,0,0,0,0,0,0,1,1,1,1,0,0,0,0,0,0,0,0};

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    string s;
    cin >> s;
    int res = 0;
    for(int i=0; i<s.size(); i++) res += er[s[i]-'A'];
    cout << res;

    return 0;
}