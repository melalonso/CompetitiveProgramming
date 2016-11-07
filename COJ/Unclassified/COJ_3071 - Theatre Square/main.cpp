#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <algorithm>
#include <vector>
#include <string>
#include <queue>
#include <limits.h>
#include <math.h>
#include <iomanip>

using namespace std;

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    double n, m, a;
    cin >> n >> m >> a;
    double ver, hor;
    ver = ceil(n/a), hor = ceil(m/a);
    cout << fixed << setprecision(0) << ver*hor;

    return 0;
}
