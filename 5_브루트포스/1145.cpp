#include<bits/stdc++.h>
using namespace std;
#define MAX 100001
int main() {
    int arr[5];
    int res[MAX];

    for (int i = 0;i < 5;i++) {
        cin >> arr[i];
    }

    int ans = 1;

    while (1) {
        int cnt = 0;
        for (int i = 0;i < 5;i++) {
            if (ans >= arr[i] && ans % arr[i] == 0) {
                cnt++;
            }
        }

        if (cnt >= 3) {
            cout << ans << "\n";
            break;
        }
        ans++;
    }
    return 0;
}