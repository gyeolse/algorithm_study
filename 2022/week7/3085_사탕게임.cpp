#include <bits/stdc++.h>
using namespace std;
int n;
string arr[50];

int func() {
    int res = 1;

    // 오 왼
    for (int i = 0;i < n;i++) {
        int tmp = 1;
        for (int j = 1;j < n;j++) {
            if (arr[i][j - 1] == arr[i][j]) tmp++;
            else {
                res = max(res, tmp);
                tmp = 1;
            }
        }
        res = max(res, tmp);
    }

    // 위 아래
    for (int i = 0;i < n;i++) {
        int tmp = 1;
        for (int j = 0;j < n - 1;j++) {
            if (arr[j + 1][i] == arr[j][i]) tmp++;
            else {
                res = max(res, tmp);
                tmp = 1;
            }
        }
        res = max(res, tmp);
    }
    return res;
}

int main() {
    cin >> n;
    int res = 0;
    for (int i = 0;i < n;i++) {
        cin >> arr[i];
    }

    for (int i = 0;i < n;i++) {
        for (int j = 0;j < n - 1;j++) {
            swap(arr[i][j], arr[i][j + 1]);
            res = max(res, func());
            swap(arr[i][j], arr[i][j + 1]);

            swap(arr[j][i], arr[j + 1][i]);
            res = max(res, func());
            swap(arr[j][i], arr[j + 1][i]);
        }
    }

    cout << res << "\n";
    return 0;
}