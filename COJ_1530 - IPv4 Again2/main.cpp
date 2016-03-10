#include <iostream>
#include <sstream>
#include <math.h>
#include <stdio.h>
#include <stdlib.h>

using namespace std;

/*
    ACCEPTED
*/

unsigned int nextPowerOf2(unsigned int n)
{
    unsigned int p = 1;
    if (n && !(n & (n - 1)))
        return n;

    while (p < n) {
        p <<= 1;
    }
    return p;
}

int main()
{
    int adNet, N, mask;
    string ip, str_n;
    stringstream stream1;
    //freopen("input", "r", stdin);
    while( cin >> ip >> adNet){
        int i = 0;
        str_n = "";
        while(i<ip.size() && ip.at(i)!='.'){
            str_n += ip.at(i);
            i++;
        }
        stream1.clear();
        stream1.str(str_n);
        stream1 >> N;

        int power = nextPowerOf2(adNet);
        int amtbits = log2(power);

        if (N>=0 && N<=127){ // A class
            cout << "255";
            int i=0;
            while(amtbits > 8){
                cout << ".255";
                amtbits -= 8;
                i++;
            }
            mask = 256 - pow(2, 8-amtbits);
            cout << "."<< mask;
            while(i++<2){cout <<".0";}

        }else if (N>=128 && N<=191){ // B class
            cout << "255.255";

            int i=0;
            while(amtbits > 8){
                cout << ".255";
                amtbits -= 8;
                i++;
            }
            mask = 256 - pow(2, 8-amtbits);
            cout << "."<< mask;
            while(i++<1){cout <<".0";}

        }else if (N>=192 && N<=223){ // B class
            cout << "255.255.255";
            mask = 256 - pow(2, 8-amtbits);
            cout << "."<< mask;
        }
        cout << "\n";

    }
    return 0;
}
