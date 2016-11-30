#include <iostream>

using namespace std;

// ACC

int main()
{
    int T;
    unsigned int N;
    cin >> T;
    while(T--){
        cin >> N;
        cout << ~N << endl;
    }
    return 0;
}
