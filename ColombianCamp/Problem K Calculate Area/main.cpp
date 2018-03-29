#include <bits/stdc++.h>

using namespace std;

typedef pair<int, int> ii;
vector<ii> points;


double areaOfPoligon() {
    double res = 0.0;
    int x1, x2, y1, y2;
    for (int i = 0; i < points.size() - 1; i++) {
        x1 = points[i].first, x2 = points[i + 1].first;
        y1 = points[i].second, y2 = points[i + 1].second;
        res += (x1 * y2 - x2 * y1);
    }
    return fabs(res) / 2.0;
}

int main() {
    int num, x, y;
    cin >> num;
    for (int i = 0; i < num; i++) {
        cin >> x >> y;
        points.push_back({x, y});
    }

    cout << round(areaOfPoligon()) << "\n";
    return 0;
}