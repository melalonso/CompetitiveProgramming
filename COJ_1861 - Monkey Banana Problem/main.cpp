#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX 105

using namespace std;

/*
    ACCEPTED
*/

int arr[2*MAX+1][MAX], N;

int main()
{
    int T;
    freopen("input","r",stdin);
    scanf("%d",&T);
    for(int k=1; k<=T; k++){
        memset(arr, 0, sizeof arr);
        scanf("%d", &N);
        scanf("%d",&arr[0][0]);
        for (int i=1; i<=N-1; i++){
            for (int j=0; j<=i; j++){
                scanf("%d", &arr[i][j]);
                if (j>0) arr[i][j] += max(arr[i-1][j], arr[i-1][j-1]);
                else arr[i][j] += arr[i-1][j];
            }
        }
        for (int i=N; i<2*N-1; i++){
            for (int j=0; j<(2*N-1-i); j++){
                scanf("%d", &arr[i][j]);
                arr[i][j] += max(arr[i-1][j], arr[i-1][j+1]);
            }
        }

        cout << "Case " << k << ": " << arr[2*N-2][0] << endl;
    }

    return 0;
}
