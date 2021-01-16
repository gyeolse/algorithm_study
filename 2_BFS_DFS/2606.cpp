#include <bits/stdc++.h>
using namespace std;
int main() {
    int x, y;
    cin >> x >> y;
    int res;
    if (x > 0 && y > 0) {
        res = 1;
    }
    else if (x > 0 && y < 0) {
        res = 4;
    }
    else if (x < 0 && y > 0) {
        res = 2;
    }
    else {
        res = 3;
    }
    cout << res;
    return 0;
}