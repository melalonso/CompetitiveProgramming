#include <bits/stdc++.h>

using namespace std;

// ACC

int main() {
    int hh, mm, ss;
    char noon[2];
    scanf("%d:%d:%d%s", &hh, &mm, &ss, &noon);
    if (noon[0] == 'P'){
        if (hh != 12) hh += 12;
    } else if (hh == 12) hh = 0;
    printf("%02d:%02d:%02d\n", hh, mm, ss);
    return 0;
}