#include <bits/stdc++.h>
using namespace std;
string s;
int sz;
int res = 0;
bool isPell(int n) {
    int half = (sz - n) / 2;
    for (int i = 0;i < half;i++) {
        if (s[n + i] != s[sz - 1 - i]) return false;
    }
    return true;
}

int main() {
    cin >> s;
    sz = s.size();

    for (int i = 0;i < sz;i++) {
        if (isPell(i)) {
            res = sz + i;
            cout << res << "\n";
            return 0;
        }
    }
}