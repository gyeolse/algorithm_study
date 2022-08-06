#include <bits/stdc++.h>
using namespace std;
int n;
double arr[10001];
double multiply[10001];

int main(void) {
    cin >> n;
    for (int i = 0;i < n;i++) {
        cin >> arr[i];
    }

    // 1. multipy 배열을 만들어줌 
    for (int i = 0;i < n;i++) {
        multiply[i] = arr[i];
    }

    // 2. 배열 세팅 
    double res = 0.0;
    for (int i = 1;i < n;i++) {
        if (multiply[i] * multiply[i - 1] >= multiply[i]) {
            multiply[i] = multiply[i - 1] * multiply[i];
        }
        res = max(res, multiply[i]);
    }

    printf("%.3lf", res);
    return 0;
}
