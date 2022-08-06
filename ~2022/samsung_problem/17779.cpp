#include <bits/stdc++.h>
using namespace std;
struct coord {
    int x; int y;
};
int n;
int arr[20][20];
int ans = 987654321;
coord square[4];

bool isAvailable(int x, int y, int d1, int d2) {

    if (x + d1 >= n || y - d1 < 0) return false;
    if (x + d2 >= n || y + d2 >= n) return false;
    if (x + d1 + d2 >= n || y - d1 + d2 >= n) return false;
    if (x + d2 + d1 >= n || y + d2 - d1 < 0) return false;

    return true;
}

void labeling(int a, int b, int c, int d) {

    // labeling 해주는 과정
    int label[20][20];

    // 처음에 5로 세팅
    for (int i = 0;i < n;i++) {
        for (int j = 0;j < n;j++) {
            label[i][j] = 5;
        }
    }

    // 1로 세팅
    int subArea = 0;
    for (int i = 0;i < square[1].x; i++) {
        if (i >= square[0].x) subArea++;
        for (int j = 0;j <= square[0].y - subArea;j++) {
            label[i][j] = 1;
        }
    }

    int plusArea = 0;
    for (int i = 0;i <= square[2].x;i++) {
        if (i > square[0].x) plusArea++;
        for (int j = square[0].y + 1 + plusArea; j < n;j++) {
            label[i][j] = 2;
        }
    }

    subArea = 0;
    for (int i = n - 1; i >= square[1].x; i--) {
        if (i < square[3].x) subArea++;
        for (int j = 0;j < square[3].y - subArea;j++) {
            label[i][j] = 3;
        }
    }

    plusArea = 0;
    for (int i = n - 1;i > square[2].y; i--) {
        if (i <= square[3].x) plusArea++;
        for (int j = square[3].y + plusArea; j < n;j++) {
            label[i][j] = 4;
        }
    }

    int res[6] = { 0,0,0,0,0,0 };
    for (int i = 0;i < n;i++) {
        for (int j = 0;j < n;j++) {
            res[label[i][j]] = res[label[i][j]] + arr[i][j];
        }
    }


    sort(res, res + 6);
    int df = res[5] - res[1];
    ans = min(ans, df);
}
int main() {

    // input
    cin >> n;
    for (int i = 0;i < n;i++) {
        for (int j = 0;j < n;j++) {
            cin >> arr[i][j];
        }
    }

    // 완전탐색
    for (int i = 0;i < n;i++) {
        for (int j = 1;j < n;j++) {
            for (int d1 = 1; d1 <= j;d1++) {
                for (int d2 = 1;d2 < (n - j); d2++) { // 왜 <= 이 아니지
                    if (isAvailable(i, j, d1, d2) == true) {
                        square[0].x = i; square[0].y = j;
                        square[1].x = i + d1; square[1].y = j - d1;
                        square[2].x = i + d2; square[2].y = j + d2;
                        square[3].x = i + d1 + d2; square[3].y = j - d1 + d2;
                        labeling(i, j, d1, d2);
                    }
                }

            }
        }
    }

    cout << ans << "\n";
    return 0;
}