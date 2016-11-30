#include <iostream>
#include <stdio.h>
#include <string.h>

#define MAXN 15
using namespace std;

int N, K, P, *nums;


/*
    ACCEPTED
*/

int gcd (int a, int b){
  int c;
  while ( a != 0 ) {
     c = a; a = b%a;  b = c;
  }
  return b;
}

int DP(int i, int sum, int m){
    if (!m) return (gcd(sum, P) != 1) ? 1: 0;
    if (i==N) return 0;
    return DP(i+1, sum + nums[i], m-1) + DP(i+1, sum, m);
}

int main()
{
    int res;
    freopen("input","r",stdin);
    while (scanf("%d %d %d",&N, &K, &P) != EOF){
        nums = new int[N];
        for (int i=0; i<N; i++) scanf("%d",&nums[i]);
        res = DP(0, 0, K);
        printf("%d\n",res);
    }

    return 0;
}
