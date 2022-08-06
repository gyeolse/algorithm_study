#include <bits/stdc++.h>
using namespace std;
#define MAX 1000001

int n;
long long arr[MAX];
queue<long long> que;

int main() {
    memset(arr, 0, sizeof(arr));
    cin >> n;

    for (int i = 1;i <= 9;i++) {
        que.push(i);
        arr[i] = i;
    }

    int idx = 9;
    while (idx <= n) { // 1. n 일 때까지 반복
        if (que.empty()) break; // 비어있다 == 없다

        long long tmp = que.front(); que.pop();

        long long lastNum = tmp % 10; // 제일 마지막 숫자 ... 하 type

        for (int i = 0;i < lastNum;i++) {
            que.push(tmp * 10 + i);
            arr[++idx] = tmp * 10 + i;
        }
    }

    // arr [n] == 0 은 ok . n이 0일땐 -> 0번째 감소수  
    if (arr[n] == 0 && n) cout << -1 << "\n";
    else cout << arr[n] << "\n";
    return 0;
}