#include <bits/stdc++.h>
using namespace std;

char letters[] = {'A','H','I','M','O','T','U','V','W','X','Y'};

/*
 * ACCEPTED
 */

bool check(string s) {
    bool valid = false;
    for (int i = 0; i < s.size(); i++) {
        for (int j=0; j<11; j++) {
            if (s[i] == letters[j]) valid = true;
        }
        if (!valid) return false;
        valid = false;
    }
    return true;
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	int N;
    string name, old;
	cin >> N;
	while( N-- ){
        cin >> name, old = name;
        reverse(name.begin(), name.end());
		cout << ( check(name) && name == old ? "YES\n" : "NO\n") ;
	}
	return 0;
}