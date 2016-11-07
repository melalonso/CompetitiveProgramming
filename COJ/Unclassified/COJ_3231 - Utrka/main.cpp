#include <iostream>
#include <set>
#include <stdio.h>
#include <stdlib.h>

using namespace std;

int main()
{
    int n;
    freopen("input","r",stdin);
    scanf("%d", &n);
    set<string> names;
    string name;
    for (int i=0; i<n ;i++){
        cin >> name;
        names.insert(name);
    }
    n--;
    while(n--){
        cin >> name;
        names.erase (names.find(name));
    }

    for(set<string>::iterator it=names.begin(); it!=names.end(); ++it)
        cout << *it << std::endl;

    return 0;
}
