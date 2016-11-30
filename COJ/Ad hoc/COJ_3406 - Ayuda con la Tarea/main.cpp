#include <iostream>
#include <stdio.h>

using namespace std;

int main()
{
    int cases;
    string n;
    scanf("%d",&cases);
    while (cases--){
        cin >> n;
        cout << n << string(n.size(),'0') << endl;
    }
    return 0;
}
