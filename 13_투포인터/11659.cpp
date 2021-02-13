#include <bits/stdc++.h>
#define MAX 100001

using namespace std;
int n, m;
int sumArr[MAX];
int inputArr[MAX];
int main() {
    cin.tie(NULL); ios::sync_with_stdio(false);

    cin >> n >> m; //5 3
    for (int i = 1;i <= n;i++) {
        cin >> inputArr[i];
    }

    //누적합 수행후, sumArr에 저장
    for (int i = 1;i <= n;i++) {
        if (i == 1) {
            sumArr[i] = inputArr[i];
        }
        else {
            sumArr[i] = sumArr[i - 1] + inputArr[i];
        }
    }

    //반복 횟수
    for (int i = 1;i <= m;i++) {
        int a, b;
        cin >> a >> b;
        //누적합 : 1~b - 1~(a-1) 한 것이 누적합
        cout << sumArr[b] - sumArr[a-1]<<"\n";
    }
    return 0;
}