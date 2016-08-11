#include <iostream>
#include <stdio.h>
#include <stdlib.h>

using namespace std;

int main()
{
    int l1, l2;
    string s1, s2;
    freopen("input","r",stdin);
    scanf("%d",&l1);
    cin >> s1;
    scanf("%d",&l2);
    cin >> s2;

    int ind = 0, res = 0;
    for(int i=0; i < l1; i++){
        if (s1[i] == s2[ind]) ind++;
        if (ind==l2){
            ind = 0;
            res++;
        }
    }

    (!res) ? printf("-1\n") : printf("%d\n", l1 - (res * l2));
    return 0;
}
