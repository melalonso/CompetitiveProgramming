#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <algorithm>
#include <vector>
#include <limits.h>
#include <math.h>

using namespace std;

// 4294967295

/*
    ACCEPTED
    Check if number of factors is even or odd (perfect squared)
*/

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie();
    freopen("input","r",stdin);
    unsigned int n, nf;
    while(cin >> n && n!=0){
        nf = sqrt(n);
        cout << (nf*nf==n ? "yes\n" : "no\n");
    }
    return 0;
}
