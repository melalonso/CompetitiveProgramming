#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <fstream>

using namespace std;



int main()
{
    int L;

    string d, p;
    //ofstream out("salida2");

    freopen("input","r",stdin);
    while(scanf("%d",&L),L){
        p = "+x";
        L--;
        while(L--){
            cin >> d;
            if (p=="+x" && d!="No" ) p = d;
            else if ( p=="-x" && d!="No"){
                if (d=="+y") p = "-y";
                else if (d=="-y") p = "+y";
                else if (d=="+z") p = "-z";
                else p = "+z";
            }else if ( p==d){
                p = "-x";
            }
            else if ( p[1] == d[1]){
                p = "+x";
            }
        }
        cout << p <<endl;
    }
    return 0;
}
