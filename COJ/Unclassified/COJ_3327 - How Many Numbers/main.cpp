#include <iostream>
#include <string.h>
using namespace std;

long long dp[20][20];

/*
    ACCEPTED.
*/

void calc(){
	memset(dp, 0, sizeof dp);
	dp[1][0] = 8;
	dp[0][1] = 10;
	//all others are initially 0
	for (int e=0; e<=18; e++){
		for (int o=0; o<=18; o++){
	  		if(e + o > 1 && e + o <= 18){
	   			dp[e][o] = 0;
	   			if(e > 0) dp[e][o] += 5 * dp[e-1][o];
	   			if(o > 0) dp[e][o] += 5 * dp[e][o-1];
	  		}
	 	}
	}
	dp[1][0]++; //Special case: 1 0
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie();
	int e,o;
	calc();
	while(cin >> e >> o && e||o){
		cout << dp[e][o]<<"\n";
	}
	return 0;
}
