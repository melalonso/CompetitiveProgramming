#include <iostream>
#include <math.h>

using namespace std;

// ACC

int main()
{
    int n, a, b, c, res;
    cin >> n;
    while(n--){
        cin >> a >> b >> c;
        res = pow(b, 2) - 4*a*c;
        cout << (res >= 0 ? "SI\n" : "NO\n");
    }
    return 0;
}
