#include <iostream>
#include <stdlib.h>
#include <stdio.h>

using namespace std;

int main()
{
    int cases;
    long long n;
    freopen("input","r",stdin);
    cin >> cases;
    while(cases--){
        cin >> n;
        if (n%2) n <<= 1;
        else while( !(n%2) ) n >>= 1;
        cout << n << endl;
    }
    return 0;
}
