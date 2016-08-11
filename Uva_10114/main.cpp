#include <iostream>
#include <stdio.h>
#include <stdlib.h>

using namespace std;

int main()
{
    int recordsNo, ind, month, months;
    double carValue, owed, downPayment, loanAmount, perMonth;

    freopen("input","r",stdin);

    while(scanf("%d %lf %lf %d",&months,&downPayment
    ,&loanAmount,&recordsNo),months>0){
        double deprMonth[months];
        fill(deprMonth,deprMonth+months,-1.0);

        while(recordsNo--){
            scanf("%d",&ind);
            scanf("%lf",&deprMonth[ind]);
        }

        for(int i =1; i<months; i++)
            if(deprMonth[i]==-1.0) deprMonth[i] = deprMonth[i-1];

        month = 0;
        carValue = downPayment + loanAmount;
        carValue *= 1-deprMonth[month];
        owed = loanAmount;
        perMonth = loanAmount/months;

        while(carValue<owed){
            owed -= perMonth;
            carValue *= 1-deprMonth[++month];
        }

        month==1 ? printf("%d month\n",month) : printf("%d months\n",month);

    }
    return 0;
}
