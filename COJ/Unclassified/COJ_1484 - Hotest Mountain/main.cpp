#include <iostream>
#include <stdio.h>
#include <stdlib.h>

using namespace std;

/*
    ACCEPTED
*/

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    freopen("input", "r", stdin);
    int N,index;
    double max=0.0, tmp;
    cin >> N;
    for (int i=0; i<N; i++){
        cin >> tmp;
        if (tmp >= max)index=i+1, max = tmp;
    }
    cout << index;
    return 0;
}
