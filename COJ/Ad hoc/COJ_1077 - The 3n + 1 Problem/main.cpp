#include <iostream>
#include <stdio.h>

using namespace std;

int main() {
	long long n, total, maxi;
	int lower, upper, a, b;
	freopen("input","r",stdin);
	while (scanf("%d %d",&a, &b) != EOF){
        maxi = 0;
        if (a>b){
            int tmp = a;
            lower = b;
            upper = tmp;
        }else{
            lower = a;
            upper = b;
        }
        for (int i=lower; i <= upper; i++){
            n = i;
            total = 1;
            while (n != 1){
                n%2 ? n = (n*3)+1 : n /= 2;
                total++;
            }
            maxi = max(maxi,total);
		}

		printf("%d %d %d\n",a,b,maxi);
    }

	return 0;
}
