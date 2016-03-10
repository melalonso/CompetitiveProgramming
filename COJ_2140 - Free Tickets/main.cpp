#include <iostream>
#include <cmath>
using namespace std;

#define MAX 8002
int main(){
    int cases,n,exp=2,j;
    long long arr[MAX];
    arr[0] = 5;
    for (int i = 1; i<MAX; i++){
        arr[i] = pow(5,exp);
        for(j=0; i+j+1<MAX && j<i; j++){
            arr[i+j+1] = arr[i] + arr[j];
        }
        i += j;
        exp++;
    }
    cin >> cases;
    while(cases--){
        cin >> n;
        cout << fixed << arr[n-1] << endl;
    }
    return 0;
}
