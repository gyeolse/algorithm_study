#include <bits/stdc++.h>
using namespace std;
int h, w;
int ans;
int widthArr[501];

int main() {
    cin >> h >> w; // 가로, 세로 

    for (int i = 0;i < w;i++) {
        int a; cin >> a; widthArr[i] = a;
    }

    for (int i = 1; i < w - 1;i++) {
        int left_ = 0; int right_ = 0;

        // left side
        for (int j = 0; j < i;j++) {
            left_ = max(left_, widthArr[j]);
        }

        // right side
        for (int j = i + 1;j < w;j++) {
            right_ = max(right_, widthArr[j]);
        }

        int curRes = min(left_, right_);

        ans += max(0, curRes - widthArr[i]);
    }

    cout << ans << "\n";
}