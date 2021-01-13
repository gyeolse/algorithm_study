#include <bits/stdc++.h>
using namespace std;

int main() {
    cin.tie(NULL);
    ios::sync_with_stdio(false);
    int n;
    cin >> n;

    int arr[20][20];
    for (int i = 0;i < n;i++) {
        for (int j = 0;j < n;j++) {
            cin >> arr[i][j];
        }
    }

    vector<int> forLoop;

    for (int i = 0;i < n / 2;i++) {
        forLoop.push_back(0);
    }
    for (int i = n / 2;i < n;i++) {
        forLoop.push_back(1);
    }
    int start_res = 0;
    int link_res = 0;

    int res = 999999;

    do
    {
        start_res = 0;
        link_res = 0;
        for (int i = 0;i < n;i++) {
            for (int j = 0;j < n;j++) {
                if (i == j) continue;
                if (forLoop[i] == forLoop[j]) {
                    if (forLoop[i] == 0) {
                        start_res += arr[i][j];
                        // start_res += arr[j][i];
                    }
                    else if (forLoop[i] == 1) {
                        link_res += arr[i][j];
                        // link_res += arr[j][i];
                    }
                }
            }
        }
        // start_res /= 2;
        // link_res /= 2;
        res = min(res, abs(start_res - link_res));

    } while (next_permutation(forLoop.begin(), forLoop.end()));

    cout << res << "\n";
    return 0;
}