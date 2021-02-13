#include <bits/stdc++.h>
using namespace std;
#define MAX 100001
long long arr[MAX];
long long n, m;

int main() {
    cin.tie(NULL); ios::sync_with_stdio(false);
    cin >> n >> m;

    for (int i = 0;i < n;i++) {
        cin >> arr[i];
    }
    sort(arr, arr + n);

    long long start = 0;
    long long end = n - 1;
    long long res = arr[start] - arr[end];

    while (start < end) {
        long long cur = arr[start] - arr[end];

        if (abs(cur) >= abs(m)) {
            res = abs(cur);
        }

        if (cur <= 0) {
            start++;
        }
        else {
            end++;
        }
    }

    cout << res << "\n";
    return 0;
}