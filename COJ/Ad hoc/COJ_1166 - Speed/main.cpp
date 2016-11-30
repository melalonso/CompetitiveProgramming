#include <iostream>

using namespace std;

/*
    ACCEPTED
*/

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    int cases, even, odd, n, x;
    cin >> cases;
    while(cases--){
        cin >> n;
        while(n--){
            cin >> x;
            x%2 ? odd++ : even++;
        }
        cout << even<< " even and "<<odd<<" odd."<<"\n";
        odd = even = 0;
    }
    return 0;
}
