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
    long long N, M;
    while(cin >> N >> M){
        cout << "Triangles: " << ( ((N*M*(M-1))>>1) + ((M*N*(N-1))>>1) )<< "\n";
        cout << "Quadrilaterals: " << ( ((N*(N-1)*M*(M-1))>>2) ) << "\n\n";
    }
    return 0;
}
