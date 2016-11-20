#include <bits/stdc++.h>

using namespace std;

// ACC

char letters[] = {'A','B','C','D','E','F','G','H','I','J','K','L',
                  'M','N','O','P','Q','R','S','T','U','V','W','X','Y','Z','_','.'};

int main() {
    ios::sync_with_stdio(0);
    //cin.tie(0);
    int N;
    string S;
    while (cin >> N && N){
        cin >> S;
        reverse(S.begin(), S.end());
        for (int i=0; i<S.size(); i++){
            if (S[i]=='.'){
                cout << letters[(27+N)%28];
            }else if (S[i]=='_'){
                cout << letters[(26+N)%28];
            }else{
                cout << letters[(S[i]-65 + N)%28];
            }
        }
        cout << "\n";
    }
    return 0;
}