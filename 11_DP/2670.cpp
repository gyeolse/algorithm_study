#include <bits/stdc++.h>
using namespace std;
int n;
double arr[10001];
double mulArr[10001];

int main(void) {
    cin >> n;
    for (int i = 0;i < n;i++) {
        cin >> arr[i];
    }

    int res = 0;
    int start = 0; int end = 0;

    mulArr[0] = arr[0];

    for (int i = 1;i < n;i++) {
        mulArr[i] = mulArr[i - 1] + arr[i];
    }

    for (int i = 0;i < n;i++) {
        cout << mulArr[i] << " ";
    }
    // while (start <= end && end <= n) {

    // }


    return 0;
}
