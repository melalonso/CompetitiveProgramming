#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <vector>

#define vs vector<string>
using namespace std;

int BT(vs words, string curr, int sol){

    if (words.size()==0) return sol;

    int last = curr.size()-1;
    int ans = -100000;
    for(int i=0;i<words.size(); i++){
        if (curr[last] == words[i][0]){
            words.erase(words.begin()+i);
            ans = max(ans, BT(words, words[i], sol + words[i].size()));
        }
    }
    return max(ans, sol);
}

int main()
{
    int cases, wa;
    vs words;
    string w;
    freopen("input","r",stdin);
    scanf("%d",&cases);
    while(cases--){
        scanf("%d",&wa);
        for (int i=0; i<wa; i++){
            cin >> w;
            words.push_back(w);
        }
        int res = -100000;
        for (int i=0; i<wa; i++){
            words.erase(words.begin()+i);
            res = max(res, BT(words, words[i], 0));
            cout << "Regreso "<<res<<endl;
        }
        printf("%d\n",res);
    }
    return 0;
}

