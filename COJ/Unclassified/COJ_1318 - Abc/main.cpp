#include <iostream>

using namespace std;

/*
    ACCEPTED
*/

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    int nums[3], A, B, C;
    char c;
    cin >> A >> B >> C;
    nums[0] = min(min(B, C),A);
    nums[2] = max(max(B, C),A);
    nums[1] = nums[0]^nums[2]^A^B^C;
    for (int i=0; i<3; i++){
        cin >> c;
        cout << nums[c-'A'];
        if (i<2) cout << " ";
    }
    return 0;
}
