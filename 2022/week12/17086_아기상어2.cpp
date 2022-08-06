#include <bits/stdc++.h>
using namespace std;
#define MAX 55
int board[MAX][MAX];
int n, m;
int dirX[8] = { -1, -1, -1, 0, 0, 1, 1, 1 };
int dirY[8] = { -1, 0, 1, -1, 1,-1 ,0, 1 };
queue<pair<int, int>> que;
int curRes = 0;
int main() {
    cin >> n >> m;

    for (int i = 0;i < n;i++) {
        for (int j = 0;j < m;j++) {
            int a = 0; cin >> a;
            if (a == 1) que.push({ i,j });
            board[i][j] = a;
        }
    }

    // solve
    while (!que.empty()) {
        pair<int, int> cur = que.front(); que.pop();
        for (int dir = 0;dir < 8;dir++) {
            int curX = cur.first + dirX[dir];
            int curY = cur.second + dirY[dir];
            if (curX < 0 || curY < 0 || curX >= n || curY >= m) continue;
            if (board[curX][curY] != 0) continue;
            que.push({ curX, curY });
            board[curX][curY] = board[cur.first][cur.second] + 1;
        }
    }

    // output
    for (int i = 0;i < n;i++) {
        for (int j = 0;j < m;j++) {
            curRes = max(curRes, board[i][j]);
            // cout << board[i][j] << " ";
        }
        // cout << endl;
    }

    cout << curRes - 1 << "\n";
    return 0;
}