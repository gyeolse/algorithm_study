#include <bits/stdc++.h>
using namespace std;
#define MAX 100001
int s, n;
long long arr[MAX];
long long sum[MAX];
int main() {
    cin >> n >> s;

    for (int i = 0;i < n;i++) {
        cin >> arr[i];
    }

    sum[0] = arr[0];

    for (int i = 1;i < n;i++) {
        sum[i] += sum[i - 1] + arr[i];
    }

    int start = 0; int end = 0;

    int res = 987654321;

    while (start <= end && end < n) {
        int cur = sum[end] - sum[start - 1];

        if (cur > s) {
            res = min(res, (end - start) + 1);
            start++;
        }
        else if (cur == s) {
            res = min(res, (end - start) + 1);
            end++;

        }
        else {
            end++;
        }
    }

    if (res == 987654321) {
        cout << 0 << "\n";
    }
    else {
        cout << res << "\n";
    }
    return 0;
}