#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <algorithm>
#include <vector>
#include <string>
#include <queue>
#include <limits.h>

using namespace std;

/*
    ACCEPTED
*/

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    int N, B, T, amount;
    freopen("input","r",stdin);
    char type;
    cin >> N;
    while(N--){
        cin >> B >> T;
        while(T--){
            cin >> type >> amount;
            type=='C' ? B+=amount : B-=amount;
        }
        cout << B << "\n";
    }
    return 0;
}
