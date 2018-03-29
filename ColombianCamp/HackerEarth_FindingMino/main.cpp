#include <bits/stdc++.h>

using namespace std;

// ACC

double func(double x){
    return (2*x*x) - (12*x) + 7;
}

double ts(double start, double end){
    double l = start, r = end;

    for(int i=0; i<200; i++) {
        double l1 = (l*2+r)/3;
        double l2 = (l+2*r)/3;
        if(func(l1) < func(l2)) r = l2; else l = l1;
    }

    double x = l;

    return func(x);
}

int main()
{
    int n, a, b;
    cin >> n;
    for(int i=0; i<n; i++){
        cin >> a >> b;
        cout.setf(ios::fixed);
        cout << setprecision(0) << ts(a, b) << "\n";
    }

    return 0;
}
