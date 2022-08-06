#include <bits/stdc++.h>
using namespace std;
int arr[5] = { 1,2,3,4,5 };
bool select[5];

void dfs(int idx, int cnt) {
    if (cnt == 3) {
        for (int i = 0;i < 5;i++) {
            if (select[i] == true) {
                cout << arr[i] << " ";
            }
        }
        cout << endl;
        return;
    }

    for (int i = idx;i < 5;i++) {
        if (select[i] == true) continue;
        select[i] = true;

        dfs(i, cnt + 1);
        select[i] = false;
    }
}
int main() {

    dfs(0, 0);
    return 0;
}