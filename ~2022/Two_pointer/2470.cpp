#include <bits/stdc++.h>
using namespace std;

int n;
long long arr[100001];

int main() {
    cin.tie(NULL); ios::sync_with_stdio(false);
    cin >> n;
    for (int i = 0;i < n;i++) {
        cin >> arr[i];
    }

    sort(arr, arr + n);

    int start = 0;
    int end = n - 1;

    //1. 첫번째 조건 실행 -> 무한 값 대신에 한 번 수행하는 것
    long long a_ = arr[start]; long long b_ = arr[end];
    long long res = a_ + b_;

    while (start < end) { //같아도 안됨. 같게 된다 -> 같은 수를 비교한다
        long long cur = arr[start] + arr[end]; //res_의 결과에 따라 포인터 위치 지정

        if (abs(res) > abs(cur)) {
            a_ = arr[start];
            b_ = arr[end];
            res = cur;
        }
        if (cur <= 0) { //음수
            start += 1;
        }
        else { //양수
            end -= 1;
        }

    }

    cout << a_ << " " << b_ << "\n";
    return 0;
}