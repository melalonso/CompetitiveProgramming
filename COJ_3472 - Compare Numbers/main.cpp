#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <algorithm>
#include <vector>
#include <string>
#include <queue>
#include <math.h>

using namespace std;

/*
    ACCEPTED
*/

int *pf1, *pf2;

int main()
{
    ios::sync_with_stdio(0);
    cin.tie();
    int N, M;
    double res1, res2;
    res1=res2=0;

    cin >> N;
    pf1 = new int[N];
    for(int i=0;i <N; i++)
        cin >> pf1[i];

    cin >> M;
    pf2 = new int[M];
    for(int i=0;i <M; i++)
        cin >> pf2[i];

    for(int i=0;i <N; i++)
        res1 += log(pf1[i]);

    for(int i=0;i <M; i++)
        res2 += log(pf2[i]);

    cout << (res1>res2 ? ">" : res1==res2 ? "=":"<");

    return 0;
}
