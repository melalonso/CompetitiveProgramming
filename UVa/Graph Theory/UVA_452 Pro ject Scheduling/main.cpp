#include <iostream>
#include <vector>
#include <stack>
#include <stdio.h>
#include <string.h>

#define MAX 29
using namespace std;

vector<int> graph[MAX];
int dtask[29];

void addEdge(int v, int w){
    graph[v].push_back(w);
}

void clean(){
    for (int i=0; i<MAX; i++){
        graph[i].clear();
        dtask[i] = 0;
    }
}

int DFS_aux(int u){
    int maxi=dtask[u];
    //cout << "Estoy en "<<(char)(u+'A')<<endl;
    for (int i=0; i<graph[u].size(); i++){
        int v = graph[u][i];
        //cout << "Voy a "<<(char)(v+'A')<<endl;
        maxi = max(maxi, dtask[u]+DFS_aux(v));
    }
    return maxi;
}

int DFS(){
    int maxi = 0;
    //cout << "A"<<endl;
    for (int i=0; i<MAX; i++){
        maxi = max(maxi, DFS_aux(i));
    }

    return maxi;
}

void print(){
    for (int i=0; i<MAX; i++){
        cout << (char)(i+'A') << "-> ";
        for (int j=0; j<graph[i].size(); j++){
            cout << (char)(graph[i][j]+'A')<<" ";
        }
        cout << endl;
    }
}

int main()
{
    int weight, T;
    char u, v[26], buff[1000];
    freopen("input", "r", stdin);
    scanf("%d\n",&T);
    while(T--){
        clean();
        v[0]=0;
        while(gets(buff) && strlen(buff)){
            sscanf(buff, "%c %d %s", &u, &weight, v);
            //cout << u << " "<<weight <<" "<<v<<endl;
            dtask[u-'A'] = weight;
            //cout << "Todo bien"<<endl;
            for(int i=0; i<strlen(v); i++){
                addEdge(v[i]-'A', u-'A');
            }
        }

        //cout << "Salio"<<endl;
        int res = DFS();
        printf("%d", res);
        if (T) printf("\n");

        //print();
        cout << endl;
    }
    return 0;
}
