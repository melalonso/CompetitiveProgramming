#include <bits/stdc++.h>

using namespace std;

// ACC

char chars[] = {'-', 'V', 'X', 'S', 'W', 'D', 'F', 'G', 'U', 'H', 'J', 'K', 'N',
                'B', 'I', 'O', '-', 'E', 'A', 'R', 'Y',
                'C', 'Q', 'Z', 'T', '-'};

char digit[] = {'9', '`', '1', '2', '3', '4', '5', '6', '7', '8'};

char symbol[] = {'M', '0', ',', '.', 'P', ']', '['};

int main() {
    //freopen("input", "r", stdin);
    char c;
    while((c = getchar()) != EOF){
        if (c >= 'A' && c <= 'Z') printf("%c", chars[c - 65]);
        else if (c >= '0' && c <= '9') printf("%c", digit[c - 48]);
        else {
            if (c == ' ') printf(" ");
            else if (c == '=') printf("-");
            else if (c == ';') printf("L");
            else if (c == '\'') printf(";");
            else if (c >= ',' && c <= '/') {
                printf("%c", symbol[c - 44]);
            } else {
                printf("%c", symbol[c - 87]);
            }
        }
    }
    return 0;
}
