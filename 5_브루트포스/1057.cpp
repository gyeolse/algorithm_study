#include <bits/stdc++.h>
using namespace std;

int main() {
    int n;
    double kim, lim;
    cin >> n >> kim >> lim;

    int cnt = 0;

    while (kim != lim) {
        kim = ceil(kim / 2);
        lim = ceil(lim / 2);
        cnt++;

    }


    if (cnt == 0) {
        cout << -1 << "\n";
    }
    else {
        cout << cnt << "\n";
    }

    return 0;
}