#include <iostream>

#define MAX 16
using namespace std;

int main()
{
    string countries[MAX];
    int prob[MAX][MAX];
    for (int i=0; i<MAX; i++) cin >> countries[i];

    for (int i=0; i<MAX; i++)
        for (int j=0; j<MAX; j++)
            cin >> prob[i][j];

    // XXXXXXXXXX p=Y.YY%
    double p=0;
    for (int i=0; i<MAX; i++){
        cout << setw(10) << fixed << countries[i]<<" ";


        cout << setprecision(2) << "p="<< d <<"%\n";
    }

    return 0;
}
