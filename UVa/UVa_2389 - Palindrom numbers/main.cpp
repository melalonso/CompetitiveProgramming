#include <bits/stdc++.h>
#define MAXN 5005
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    //cin.tie(0);
    int n, x;
    while (cin >> n && n) {
        vector<int> arr;
        bool found = false;
        int idx;
        for(int i=0; i<n; i++){
            cin >> x;
            if (!found && x){
                idx = i;
                found = true;
            }
            arr.push_back(x);
        }
        int res = 0, chars = 1;
        int ssize = (int) arr.size();
        idx = (idx+1)%ssize;
        while(chars <= ssize){
            if (!arr[idx%ssize] && !arr[(idx+1)%ssize]){
                arr[idx+1%ssize] = 1;
                res++;
                idx += 2;
                chars += 2;
            }else{
                idx++;
                chars++;
            }
        }
        cout << res << "\n";

    }
    return 0;
}