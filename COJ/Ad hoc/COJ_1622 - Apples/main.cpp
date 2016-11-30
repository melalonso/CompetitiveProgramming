#include <iostream>
#include <stdio.h>
#include <stdlib.h>

using namespace std;

int main()
{
    int bags, b;
    int even, odd;
    freopen("input","r",stdin);
    while(cin >> bags){
        odd = even = 0;
        while(bags--){
            cin >> b;
            b%2 ? odd++ : even++;
        }

        if (odd%2) cout << odd;
        else cout << even;
        cout << endl;
    }
    return 0;
}
