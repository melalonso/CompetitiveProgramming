#include <iostream>
#include <math.h>

using namespace std;

/*
    ACCEPTED
*/

int main()
{
    int N, M, exp = 0;
    long long res = 0;
    cin >> N >> M;
    while(N%2 && M%2){
        N = (N-1)/2;
        M = (M-1)/2;
        res += pow(4,exp);
        exp++;
    }
    cout << res ? res : 0;
    cout << endl;

    return 0;
}
