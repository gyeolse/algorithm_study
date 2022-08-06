#include <bits/stdc++.h>
using namespace std;
int n;
int t[16];
int p[16];
int ans = 0;

void func(int i, int res) {
    if (i == n) {
        ans = max(res, ans);
        return;
    }
    if (i > n) return;

    //선택
    func(i + t[i], res + p[i]);
    //선택 x
    func(i + 1, res);
}

int main() {
    cin >> n;
    for (int i = 0;i < n;i++) {
        cin >> t[i] >> p[i];
    }

    func(0, 0);

    cout << ans << "\n";
    return 0;
}