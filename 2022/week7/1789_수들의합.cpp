#include <bits/stdc++.h>
using namespace std;

int main() {
    long long s; cin >> s;
    long long res = 0;
    long long idx = 1;
    int cnt = 0;

    while (1) {
        res += idx;
        cnt++;
        if (res > s) {
            cnt--;
            break;
        }
        idx++;
    }

    cout << cnt;
}