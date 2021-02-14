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

    long long start = 0, end = 0;
    long long res = arr[n - 1] - arr[0];

    while (start <= end && end < n) {
        long long cur = arr[end] - arr[start];
        if (cur >= m) { //크거나 같은 경우
            res = min(cur, res);
            start++;
        }
        else { //작은 경우
            end++;
        }
    }
    cout << res << "\n";
    return 0;
}