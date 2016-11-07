#include <iostream>

using namespace std;

/*
 * ACC
 */

string units[] = {"zero", "one", "two", "three", "four", "five", "six", "seven", "eight", "nine", "ten"};
string teens[] = {"eleven", "twelve", "thirteen", "fourteen", "fifteen", "sixteen", "seventeen", "eighteen", "nineteen"};
string tens[] = {"ten", "twenty", "thirty", "forty", "fifty", "sixty", "seventy", "eighty", "ninety"};

int main() {
    ios::sync_with_stdio(0);
    int k, n=0;
    cin >> k;
    while(k--){
        cin >> n;
        if (n<=10) cout << units[n] << "\n";
        else if (n>10 && n<20) cout << teens[n-11] << "\n";
        else{
            cout << tens[n/10 -1];
            if (n%10) cout << "-" << units[n%10];
            cout << "\n";
        }
    }
    return 0;
}