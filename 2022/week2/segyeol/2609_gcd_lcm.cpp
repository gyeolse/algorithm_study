#include <bits/stdc++.h>
using namespace std;

int findGcd(int a, int b) {
    int c = a % b;
    while (c != 0) {
        a = b;
        b = c;
        c = a % b;
    }

    return b;
}

int main() {
    int n, m;
    cin >> n >> m;

    int gcd_ = findGcd(n, m);
    int lcm_ = (n * m) / gcd_;

    cout << gcd_ << "\n";
    cout << lcm_ << "\n";

    return 0;
}