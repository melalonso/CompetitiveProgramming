#include <bits/stdc++.h>
#define MAX_SIZE 10

using namespace std;
typedef vector<int> vi;
vi ulam;

void calc(){
    ulam.push_back(1);
    ulam.push_back(2);
    for (int i = 3, z = 0; ulam.size() < MAX_SIZE; i++, z = 0) {
        for (int j=0; j< ulam.size(); j++) {
            for (int k=0; k<ulam.size(); k++) {
                if (ulam[j] < ulam[k] && ulam[j] + ulam[k] == i)
                    z++;
            }
        }
        if (z == 1) ulam.push_back(i);
    }
}

int main() {
    ios::sync_with_stdio(false);
    //cin.tie(0);
    calc();
    cout << "Calculated\n";
    for (int i=0; i<ulam.size(); i++) cout << ulam[i]<<" ";
    return 0;
}