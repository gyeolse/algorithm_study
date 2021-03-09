#include <bits/stdc++.h>
using namespace std;

int a, b, c, d, e, f;

int main() {
    cin >> a >> b >> c >> d >> e >> f;

    int x_ = 0, y_ = 0;
    for (int i = -999;i <= 999;i++) {
        for (int j = -999;j <= 999;j++) {
            if ((a * i + b * j) == c) {
                if ((d * i + e * j) == f) {
                    x_ = i;
                    y_ = j;
                }
            }
        }
    }

    cout << x_ << " " << y_ << "\n";
    return 0;
}