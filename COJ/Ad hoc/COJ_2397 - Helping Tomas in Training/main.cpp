#include <bits/stdc++.h>

using namespace std;

// NOT ACC

int ye1, m1, d1, y2, m2, d2;
int daysPerMonth[12] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};

int leapYears(int year, int month) {
    if (month < 3) year--;
    return year / 4 - year / 100 + year / 400;
}

int solve() {
    int total1, total2;

    total1 = ye1 * 365 + d1;
    for (int i = 0; i < m1 - 1; i++) total1 += daysPerMonth[i];
    total1 += leapYears(ye1, m1);

    total2 = y2 * 365 + d2;
    for (int i = 0; i < m2 - 1; i++) total2 += daysPerMonth[i];
    total2 += leapYears(y2, m2);

    return abs(total1 - total2);
}


int main() {
    ios::sync_with_stdio(0);
    //cin.tie(0);
    freopen("output","w",stdout);
    int cases;
    cin >> cases;
    while(cases--){
        scanf("%d-%d-%d %d-%d-%d", &ye1, &m1, &d1, &y2, &m2, &d2);
        cout << solve() << "\n";
    }
    return 0;
}