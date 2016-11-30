    #include <bits/stdc++.h>
     
    using namespace std;
    int MAT[2][12900];
     
    int n, m;
    int WI[3410];
    int DI[3410];
     
    int DP(int D, int W) {
    	memset(MAT[0], 0, sizeof MAT[0]);
    	int *curr, *prev;
    	for (int d=1; d <= D; d++){
    		curr = MAT[ (d&1) ];
    		prev = MAT[ !(d&1) ];
    		for (int w=0; w <= W; w++) {
    			if (w >= WI[d]){
    				curr[w] = max( prev[w], DI[d] + prev[w - WI[d]]);
    			} else {
    				curr[w] = prev[w];
    			}
    		}
    	}
    	return MAT[D&1][W];
    }
     
    int main() {
    	cin >> n >> m;
    	for(int i = 1; i <= n; i++) cin>>WI[i]>>DI[i];
    	cout << DP(n, m) << "\n";
    	return 0;
    }