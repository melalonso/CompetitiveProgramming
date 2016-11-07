#include <iostream>

using namespace std;

/*
    ACCEPTED
*/

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    int N, M, D;
    cin >> N;
    while(N--){
        cin >> M >> D;
        cout <<D-(D/M)<<"\n";
    }
    return 0;
}
