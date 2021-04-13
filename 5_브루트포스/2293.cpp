#include <bits/stdc++.h>
using namespace std;
int n, k;

int arr[101];
int res = 0;
void func(int num, int idx) {
    if (num == k) {
        res++;
        return;
    }
    else if (num > k) {
        return;
    }

    for (int i = idx;i < n;i++) {
        func(num + arr[i], idx);
    }
}
int main() {
    cin >> n >> k;
    for (int i = 0;i < n;i++) {
        cin >> arr[i];
    }

    func(0, 0);

    cout << res << "\n";
    return 0;
}