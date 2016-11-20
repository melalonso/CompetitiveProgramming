#include <iostream>
#include <stdio.h>
#include <stdlib.h>

using namespace std;

int main()
{
    int n, p = 0;
    string line, bestPName, pName;
    double price, bestPrice;
    int metReq, bestMetReq, ind = 1;

    freopen("inputr","r",stdin);

    while(scanf("%d %d\n",&n,&p),n&p){

        bestPrice=10000000.0;
        bestMetReq = 0;
        for(int i=0;i<n;i++) getline(cin,line);

        while(p--){
            getline(cin,pName);
            scanf("%lf %d\n",&price,&metReq);

            for(int i=0;i<metReq;i++) getline(cin,line);

            if (metReq>bestMetReq){
                bestPName = pName;
                bestPrice = price;
                bestMetReq = metReq;
            }else if (metReq==bestMetReq){
                if (price<bestPrice){
                    bestPName = pName;
                    bestPrice = price;
                    bestMetReq = metReq;
                }
            }
        }

        if (ind != 1) printf("\n\n");
        printf("RFP #%d\n",ind);
        cout << bestPName;
        ind++;
    }
    return 0;
}
