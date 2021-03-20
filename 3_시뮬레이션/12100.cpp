#include <bits/stdc++.h>
using namespace std;

int board[21][21];
int tempBoard[21][21];
int n;

void rotate() {
    int tmp[21][21];
    for (int i = 0;i < n;i++) {
        for (int j = 0;j < n;j++) {
            tmp[i][j] = tempBoard[i][j];
        }
    }

    for (int i = 0;i < n;i++) {
        for (int j = 0;j < n;j++) {
            tempBoard[i][j] = tmp[n - 1 - j][i];
        }
    }
}

void tilt(int dir) {
    while (dir--) rotate();

    for (int i = 0;i < n;i++) {
        int tilted[21] = {};
        int idx = 0;
        for (int j = 0;j < n;j++) {
            if (tempBoard[i][j] == 0) continue;
            if (tilted[idx] == 0) {
                tilted[idx] = tempBoard[i][j];
            }
            else if (tilted[idx] == tempBoard[i][j]) {
                tilted[idx++] *= 2;
            }
            else {
                tilted[++idx] = tempBoard[i][j];
            }
        }

        for (int j = 0;j < n;j++) {
            tempBoard[i][j] = tilted[j];
        }
    }

}
int main() {
    cin >> n;

    for (int i = 0;i < n;i++) {
        for (int j = 0;j < n;j++) {
            cin >> board[i][j];
        }
    }

    int res = 0;
    for (int x = 0;x < 1024;x++) {
        for (int i = 0;i < n;i++) {
            for (int j = 0;j < n;j++) {
                tempBoard[i][j] = board[i][j];
            }
        }

        int brute = x;
        for (int i = 0;i < 5;i++) {
            int dir = brute % 4;
            brute /= 4;
            tilt(dir);
        }

        for (int i = 0; i < n;i++) {
            for (int j = 0;j < n;j++) {
                res = max(res, tempBoard[i][j]);
            }
        }
    }
    cout << res << "\n";
    return 0;
}