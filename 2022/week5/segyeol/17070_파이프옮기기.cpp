#include <bits/stdc++.h>
using namespace std;

int board[20][20];
int n, res;
int dirX[3] = { 0, 1, 1 }; // 가로, 대각선, 세로
int dirY[3] = { 1, 1, 0 };
struct info {
    int x, y, d; //0, 1, 2 가로, 대각선, 세로
};

queue<info> que;
void moveFunc(int x, int y, int d, int i) {
    int curX = x + dirX[i];
    int curY = y + dirY[i];
    int curD = i;
    if (board[curX][curY] == 0) {
        if (curX > 0 && curY > 0 && curX <= n && curY <= n) {
            if (i == 1) { // 대각선인 경우
                if (board[curX - 1][curY] == 1 || board[curX][curY - 1] == 1) return;
            }

            que.push({ curX, curY, curD });
        }
    }
}
int main() {
    cin >> n;
    for (int i = 1;i <= n;i++) {
        for (int j = 1;j <= n;j++) {
            cin >> board[i][j];
        }
    }

    que.push({ 1,2,0 });
    while (!que.empty()) {
        info cur = que.front(); que.pop();
        int curX = cur.x; int curY = cur.y; int curD = cur.d;
        if (curX == n && curY == n) res++; // 경우의수 ++
        if (curD == 0) { // 가로 
            for (int i = 0;i < 2;i++) {
                moveFunc(curX, curY, curD, i); // 0, 1
            }
        }
        else if (curD == 1) { // 대각선
            for (int i = 0;i < 3;i++) {
                moveFunc(curX, curY, curD, i); // 0, 1, 2
            }

        }
        else { // 세로
            for (int i = 1;i < 3;i++) {
                moveFunc(curX, curY, curD, i); // 1, 2
            }
        }
    }

    cout << res << "\n";
    return 0;
}