#include <iostream>
#include <algorithm>

using namespace std;

/*
    ACCEPTED
*/

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    int N;
    cin >> N;
    int nums[N];
    for (int i=0; i<N; i++) cin >> nums[i];
    sort(nums, nums+N);
    for (int i=0; i<N; i++){
        cout << nums[i];
        if (i<N-1) cout << "\n";
    }

    return 0;
}
