#include <bits/stdc++.h>

#define EPSILON 0.0000000000001
using namespace std;

long double arr[1002];

using namespace std;

void computeLPSArray(char str[], int M, int lps[])
{
    int len = 0;
    int i;

    lps[0] = 0;
    i = 1;

    while (i < M)
    {
        if (str[i] == str[len]) {
            len++;
            lps[i] = len;
            i++;
        }
        else // (pat[i] != pat[len])
        {
            if (len != 0)
            {
                len = lps[len-1];
            }
            else // if (len == 0)
            {
                lps[i] = 0;
                i++;
            }
        }
    }
}

int isRepeat(char str[])
{

    int n = strlen(str);
    int lps[n];
    computeLPSArray(str, n, lps);

    int len = lps[n-1];
    return (len > 0 && n%(n-len) == 0)? n-len: 0;
}

int main()
{
    char arr[1000005];
    scanf("%s", &arr);
    cout << isRepeat(arr)<< "\n";
    return 0;
}


/*
int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    long double n, q1, q2, q3, iqr, sum, a, b;
    cin >> n;
    for (int i=0; i<n; i++){
        cin >> arr[i];
        sum += arr[i];
    }
    q2 = sum/n;

    sort(arr, arr+(int)n);
    sum = 0;
    for (int i=0; i<n/2; i++){
        sum += arr[i];
    }
    q1 = sum/n;

    sum =0;
    int i;
    if ((int)n%2==0) i = n/2;
    else i = n/2+1;
    for (i; i<n; i++){
        sum += arr[i];
    }
    q3 = sum/n;

    iqr = q3 - q1;

    a = q3 + 1.5 * iqr; // above
    b = q1 - 1.5 * iqr; // below

    int res=0;
    for (int i=0; i<n; i++){
        if (arr[i]-EPSILON > a || arr[i]+EPSILON < b) res++;
    }

    cout << res << "\n";

    return 0;
}
 */