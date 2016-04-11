#include <iostream>
#include <bits/stdc++.h> // Includes saver

#define MAXN 30001
#define NRANGE 1000000
#define QUERIES 200000

using namespace std;

/*
    ACCEPTED
*/

int fenwick[MAXN], N;
bool visited[NRANGE];
int prev[NRANGE];

struct req {
    int idx, right, left, val;
    bool type;
};

bool operator <(req a, req b){
    if (a.right == b.right) return a.type < b.type;
    return a.right < b.right;
}

req arr[MAXN + QUERIES + 2];

void update(int x, int val) {
    while ( x <= MAXN-1 ) {
        fenwick[x] += val;
        x += x & -x;
    }
}

int get(int x) {
    int res = 0;
    while( x > 0 ) {
        res += fenwick[x];
        x -= x & -x;
    }
    return res;
}

/*

    Line 1: n (1 ≤ n ≤ 30000).
    Line 2: n numbers a1, a2, ..., an (1 ≤ ai ≤ 10^6).
    Line 3: q (1 ≤ q ≤ 200000), the number of d-queries.
    In the next q lines, each line contains 2 numbers i, j representing a d-query (1 ≤ i ≤ j ≤ n).

*/

int main()
{
    int n, q, i, j, x;
    ios::sync_with_stdio(0);
    freopen("input", "r", stdin);
    cin >> n;
    for (int i=0; i<n; i++){
        cin >> x;
        arr[i].val = x;
        arr[i].idx = i+1;
        arr[i].type = 0;
        arr[i].right = i+1;
        update(i+1, 1);
    }

    cin >> q;
    int ans[q];
    for (int i = n; i < n + q; i++){
        cin >> arr[i].left >> arr[i].right;
        arr[i].idx = i-n;
        arr[i].type = 1;
    }

    sort( arr, arr + q + n );

/*

    1 1 2 1 3
    3
    1 5
    2 4
    3 5

idx val right left type
1   1    1          0
2   1    2          0
3   2    3          0
4   1    4          0
5   3    5          0

0        5      1   1
1        4      2   1
2        5      3   1

1   1    1          0
2   1    2          0
3   2    3          0
4   1    4          0
1        4      2   1 Q
5   3    5          0
0        5      1   1 Q
2        5      3   1 Q


*/




    for (int i = 0; i < n + q; i++) {
        if (arr[i].type) {
            ans[ arr[i].idx ] = get( arr[i].right ) - get( arr[i].left-1 );
        } else {
            if (visited[ arr[i].val ]){
                update( prev[ arr[i].val ], -1);
            }
            visited[ arr[i].val ] = true;
            prev[ arr[i].val ] = arr[i].idx;
        }
    }

    for (int i=0; i<q; i++) cout << ans[i] << "\n";


    return 0;
}
