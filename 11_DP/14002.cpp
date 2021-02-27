#include <bits/stdc++.h>
using namespace std;

int arr[1001];
int dp[1001];
int pastIdx[1001];

void func(int num) {
    if (pastIdx[num] == -1) {
        cout << arr[num] << " ";
        return;
    }

    int next = pastIdx[num];
    func(next);
    cout << arr[num] << " ";
}
int main() {
    int n;
    cin >> n;
    for (int i = 0;i < n;i++) {
        cin >> arr[i];
    }

    fill_n(dp, n, 1);
    fill_n(pastIdx, n, -1);

    for (int i = 0;i < n;i++) {
        for (int j = 0;j < n;j++) {
            if (arr[i] > arr[j]) {
                if (dp[j] + 1 > dp[i]) {
                    dp[i] = dp[j] + 1;
                    pastIdx[i] = j;
                }
            }
        }
    }

    int s_ = *max_element(dp, dp + n);
    int idx = 0;
    for (int i = 0;i < n;i++) {
        if (s_ == dp[i]) idx = i;
    }

    cout << *max_element(dp, dp + n) << "\n";

    func(idx);

    return 0;
}