#include <bits/stdc++.h>
using namespace std;
int n, m, k;
int board[42][42];
int r, c;
int curSticker[12][12];

void rotate() {
    //temp를 선언해서, temp에 현재 스티커를 복사하고, curSticker에 다시 집어넣는 방식
    int tmp[12][12];

    for (int i = 0;i < r;i++) {
        for (int j = 0;j < c;j++) {
            tmp[i][j] = curSticker[i][j];
        }
    }

    for (int i = 0;i < c;i++) {
        for (int j = 0;j < r;j++) {
            curSticker[i][j] = tmp[r - 1 - j][i];
        }
    }
    swap(r, c);
}

bool isAvailable(int x, int y) {
    for (int i = 0;i < r;i++) {
        for (int j = 0;j < c;j++) {
            if (board[i + x][j + y] == 1 && curSticker[i][j] == 1) return false;
        }
    }

    for (int i = 0;i < r;i++) {
        for (int j = 0;j < c;j++) {
            if (curSticker[i][j] == 1) {
                board[i + x][j + y] = 1;
            }
        }
    }
    return true;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin >> n >> m >> k;
    while (k--) {
        cin >> r >> c;
        for (int i = 0;i < r;i++) {
            for (int j = 0;j < c;j++) {
                cin >> curSticker[i][j];
            }
        }

        //1. 스티커를 붙일수 있는지 체크
        //2. 스티커를 붙이기 => 차례대로 90도, 180도, 270도
        for (int dir = 0;dir < 4;dir++) {
            bool isPaste = false;
            for (int x = 0;x <= (n - r);x++) {
                if (isPaste) break;
                for (int y = 0;y <= (m - c);y++) {
                    if (isAvailable(x, y)) {
                        isPaste = true;
                        break;
                    }
                }
            }
            if (isPaste) break;
            rotate();
        }
    }
    //output
    int ans = 0;
    for (int i = 0;i < n;i++) {
        for (int j = 0;j < m;j++) {
            ans += board[i][j];
        }
    }
    cout << ans << "\n";
    return 0;
}