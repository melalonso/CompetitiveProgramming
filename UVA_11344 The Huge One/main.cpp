#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <algorithm>
#include <vector>

using namespace std;

/*
    ACCEPTED.
*/

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie();
    int N, nset, divisor, x;
    string M;
    freopen("input","r",stdin);
    cin >> N;
    while(N--){
        cin >> M;
        cin >> nset;
        bool flag = false;
        x = 0;
        while(nset--){
            cin >> divisor;
            if (!flag){
                for(int i=0; i<M.size(); i++){
                    x = x*10 + M[i]-'0';
                    x %= divisor;
                }
            }
            if (x) flag = true;
        }

        cout << M << " - ";
        cout << (flag ? "Simple.\n" : "Wonderful.\n");
    }
    return 0;
}
