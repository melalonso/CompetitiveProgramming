#include <iostream>
#include <stdio.h>
#include <stdlib.h>

using namespace std;

int main()
{
    char c;
    //freopen("input","r",stdin);

    bool left = true;
    while( ( c = getchar() ) != EOF){
        if (c == '"'){
            if (left){
                printf("``");
                left = false;
            }else{
                printf("''");
                left = true;
            }
        }else
            printf("%c",c);
    }
    return 0;
}
