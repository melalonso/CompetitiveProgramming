#include <iostream>

using namespace std;

/*
 * ACCEPTED
 */

int roads[20002];

int main() {
    int b, s;
    cin >> b;
    for (int r=1; r<=b; r++){
        cin >> s;
        for (int j=0; j<s-1; j++)  cin >> roads[j];

        int max=0, begin=0, sum=0;
        int bestBegin=1, bestEnd=1;

        for (int j=0; j<s-1; j++) {
            sum += roads[j];

            if (sum < 0) {  begin = j+1; sum = 0; }

            if (sum > max || (sum == max && j+1 - begin > bestEnd+1 - bestBegin) ){
                max = sum;
                bestEnd = j;
                bestBegin = begin;
            }

        }
        if (!max) cout << "Route "<<r<<" has no nice parts\n";
        else cout << "The nicest part of route "<<r<<" is between stops "<<bestBegin+1<<" and "<<bestEnd+2<<"\n";
    }
    return 0;
}