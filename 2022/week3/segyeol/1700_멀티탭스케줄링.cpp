#include <bits/stdc++.h>
using namespace std;
int n, k;
int scheduling[100];
int multitap[100];
int ans;

int main() {
    cin >> n >> k;
    for (int i = 0;i < k;i++) {
        int a; cin >> a; scheduling[i] = a;
    }
    int res = 0;

    // 0) init. 비어있으면 -1
    for (int i = 0;i < n;i++) {
        multitap[i] = -1;
    }

    for (int i = 0;i < k;i++) {
        bool isPlugged = false;
        // 1) 꽂혀있으면 skip
        for (int j = 0; j < n;j++) {
            if (multitap[j] == scheduling[i]) {
                isPlugged = true;
                break;
            }
        }
        if (isPlugged) continue;

        // 2) 빈곳이 있으면 setting 하고 skip 
        for (int j = 0;j < n;j++) {
            if (multitap[j] == -1) {
                multitap[j] = scheduling[i];
                isPlugged = true;
                break;
            }
        }

        if (isPlugged) continue;

        // 3) 빈곳이 없으면
        int idx; int deviceIdx = -1;
        for (int j = 0;j < n;j++) { // 플러그 갯수
            // 3-1) 누굴 뺄지 정해야함. 아예 안쓸놈 
            // 3-2) 마지막에 쓸 놈
            int last_ = 0;
            for (int cur = i + 1;cur < k;cur++) {
                if (multitap[j] == scheduling[cur]) break; // 있으면 나가고
                last_++; // last가 계속 더해질 테니까
            }

            if (last_ > deviceIdx) {
                idx = j;
                deviceIdx = last_;
            }
        }
        ans++;
        multitap[idx] = scheduling[i];
    }

    cout << ans << "\n";
    return 0;
}