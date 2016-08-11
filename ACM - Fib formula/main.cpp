#include <iostream>
#include <math.h>
#include <stdio.h>

using namespace std;

long long fib_memo[100];
long long fib_memo2[100];


void calcFibo(){
    fib_memo[0] = 0;
    fib_memo[1] = 1;
    for (int i=2; i<100;i++){
        fib_memo[i] = fib_memo[i-1] + fib_memo[i-2];
    }
}

int main()
{
    const double phi = ( 1 + sqrt(5)) / 2;
    calcFibo();
    int n = 0;
    while(n<100){
        long long res = ( pow(phi, n) - pow(-1.0 * phi, -1*n)) / sqrt(5);
        fib_memo2[n++] = res;
    }

    for( int i=0; i<100;i++){
        if (fib_memo[i]!=fib_memo2[i]) printf("%d\n",i);
    }
    return 0;
}
