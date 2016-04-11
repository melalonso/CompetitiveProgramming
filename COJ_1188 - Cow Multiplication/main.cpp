#include <iostream>

using namespace std;

/*
    ACCEPTED
*/

int multiply(int a, int b){
    if (!a) return 0;
    int digit = a%10, res=0;
    int tmp = b;
    while(tmp){
        res += digit*(tmp%10);
        tmp /= 10;
    }
    return res + multiply(a/10,b);
}

int main()
{
    int A, B;
    cin >> A >> B;
    cout << multiply(A, B);
    return 0;
}
