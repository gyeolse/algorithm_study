#include <bits/stdc++.h>
using namespace std;
#define MAX 1000001

int n;
long long arr[MAX];
queue<long long> que; //long long이 문제였다. 
int idx = 9;

void ans() {
    //idx 9부터 시작
    while (idx <= n) {
        if (que.empty()) {
            return;
        }

        //큐의 제일 앞의 수를 꺼낸다. 
        long long temp = que.front(); que.pop();

        //마지막 자리 숫자를 본다. 
        int lastNum = temp % 10;

        //마지막 자리 수보다 작은 숫자들을 계속 붙여나간다
        for (int i = 0;i < lastNum;i++) {
            que.push(temp * 10 + i);
            arr[++idx] = temp * 10 + i;
        }
    }

}

int main() {
    memset(arr, 0, sizeof(arr));

    cin >> n;
    for (int i = 1;i <= 9;i++) {
        que.push(i);
        arr[i] = i;
    }

    ans();

    //n번쨰 감소하는 수가 없18다면
    if (arr[n] == 0 && n) cout << -1 << "\n";
    else cout << arr[n] << "\n";
    return 0;
}