//============================================================================
// Name        : G.cpp
// Author      : 
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
vector<vector<int> > AdjList;
ll x[1005];
ll y[1005];
ll r[1005];
int N;

bool intersects(int i, int j){
	ll dX = (x[i]-x[j]);
	ll dY = (y[i]-y[j]);
	ll rS = (r[i]+r[j]);
	return dX*dX+dY*dY <= rS*rS;
}

void calcGraph(){
	for (int i = 0; i < N; i++){
		for (int j = i+1; j < N; j++){
			if (intersects(i,j)) {
				AdjList[i].push_back(j);
				AdjList[j].push_back(i);
			}
		}
	}
}

int color[1005];

inline int opposite(int c){
	return 3-c;
}

bool isBipartite(int i, int c){
	color[i]=c;
	for (auto v : AdjList[i]){
		if (! color[v]){
			if (! isBipartite(v,opposite(c))) return false;
		} else if (color[v] != opposite(c)){
			return false;
		}
	}
	return true;
}

void solve(){
	calcGraph();
	if (! isBipartite(0,1)){
		cout << "The input gear cannot move.\n";
		return;
	} else if (! color[N-1]){
		cout << "The input gear is not connected to the output gear.\n";
	} else {
		if (color[0]!=color[N-1]) cout << "-";
		ll g = __gcd(r[0],r[N-1]);
		cout << (r[N-1]/g) << ":" << (r[0]/g) << "\n";
	}

}

int main() {
	cin >> N;
	AdjList.assign(N, vector<int>());
	for (int i = 0; i < N; i++){
		cin >> x[i] >> y[i] >> r[i];
	}
	solve();
}
