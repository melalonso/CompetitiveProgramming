#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <algorithm>
#include <vector>
#include <string>
#include <queue>
#include <limits.h>

using namespace std;

/*
    ACCEPTED
*/

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    freopen("input", "r", stdin);
    int N;
    cin >> N;
    int nums[N], ratio;
    bool flag=true;
    for (int i=0; i<N; i++) cin >> nums[i];
    sort(nums, nums+N);
    ratio = nums[1] - nums[0];
    for(int i=2; i<N; i++){
        if (nums[i]-nums[i-1]!=ratio) flag = false; break;
    }
    cout << (flag ? "YES\n":"NO\n");
    return 0;
}
