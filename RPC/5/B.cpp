#include <iostream>
using namespace std;

int arr[305][305];
int n, m, x;

int maximo(int i, int j){
	if (i >= n)	return 0;
	int res = 0;
	res += max(arr[i][j] + maximo(i+2, j), maximo(i+1, j));
	return res;
}

int dp(int j) {
	if (j >= m) return 0;
	int res = 0;
	res = max(maximo(0, j) + dp(j+2), dp(j+1));
	return res;
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	while(cin >> n >> m){
		for (int i=0 ;i<n; i++){
			for (int j=0 ;j<m; j++){
				cin >> arr[i][j];
			}
		}
		cout << max(dp(0), dp(1))<<"\n";
	}
	return 0;
}