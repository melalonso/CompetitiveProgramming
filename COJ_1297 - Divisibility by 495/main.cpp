#include <iostream>
#include <stdio.h>

using namespace std;

/*
    ACCEPTED.
*/

char N[1005];

int main()
{
    int T, i, sumE, sumO;
    scanf("%d", &T);
    while(T--){
        scanf("%s",&N);
        i = sumO = sumE = 0;
        if (N[0] == '-') i++;
        while(N[i] != '\0'){
            if (i%2) sumO += N[i]-'0';
            else     sumE += N[i]-'0';
            i++;
        }
        if ( (N[i-1]-'0')%5==0 && (sumE-sumO)%11==0
            && (sumE+sumO)%9==0) printf("YES\n");
        else printf("NO\n");
    }
    return 0;
}
