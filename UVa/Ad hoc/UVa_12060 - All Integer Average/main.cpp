#include <bits/stdc++.h>

using namespace std;

// ACC

int amtDigits(int x) {
    int res = 0;
    while (x) {
        x /= 10;
        res++;
    }
    return res;
}

int main() {
    ios::sync_with_stdio(0);
    //cin.tie(0);
    int n, sum, x, idx = 1, a, gcd, total;
    bool neg;
    while (cin >> n && n) {
        sum = 0, neg = false;
        for (int i = 0; i < n; i++) {
            cin >> x;
            sum += x;
        }
        if (sum < 0) {
            neg = true;
            sum = abs(sum);
        }

        cout << "Case " << idx++ << ":\n";
        if (sum % n == 0) {
            if (neg) cout << "- ";
            cout << sum / n << "\n";
        } else {
            gcd = __gcd(sum, n);
            n /= gcd;
            sum /= gcd;
            if (sum > n) {
                a = sum / n;
                sum = sum%n;

                total = amtDigits(a) + (amtDigits(n) -amtDigits(sum));
                if (neg) total+=2;
                for (int i=0; i<total;i++) cout << " ";
                cout << sum << "\n";

                if (neg) cout << "- ";
                cout << a;
                for (int i=0; i<amtDigits(n); i++) cout << "-";
                cout << "\n";

                total += (amtDigits(sum) - amtDigits(n));
                for (int i=0; i<total;i++) cout << " ";
                cout << n << "\n";
            } else {

                total =  amtDigits(n) - 1;
                if (neg) total+=2;
                for (int i=0; i<total;i++) cout << " ";
                cout << sum << "\n";

                if (neg) cout << "- ";
                for (int i=0; i<amtDigits(n); i++) cout << "-";
                cout << "\n";

                total += (amtDigits(sum) - amtDigits(n));
                for (int i=0; i<total;i++) cout << " ";
                cout << n << "\n";
            }
        }
    }
    return 0;
}