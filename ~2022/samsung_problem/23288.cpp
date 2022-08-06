#include <bits/stdc++.h>
using namespace std;
#define MAX 25

int n, m, k;
int arr[MAX][MAX];
bool chk[MAX][MAX];

int dice[7] = { 0, 1, 2, 3, 4, 5, 6 };
int dirY[4] = { 1, -1, 0, 0 };
int dirX[4] = { 0, 0, 1, -1 };
int ans;

int changeDirection(int d) {
    if (d == 0) {
        return 1;
    }
    else if (d == 1) {
        return 0;
    }
    else if (d == 2) {
        return 3;
    }
    else if (d == 3) {
        return 2;
    }
    else {
        return -1;
    }
}

void getScore(int curX, int curY) { // bfs
    memset(chk, false, sizeof(chk));

    int num = arr[curX][curY]; // value
    int cnt = 1;

    queue<pair<int, int>> que;

    que.push({ curX, curY });
    chk[curX][curY] = true;

    while (!que.empty()) {
        int curX = que.front().first;
        int curY = que.front().second;
        que.pop();

        for (int i = 0;i < 4;i++) {
            int dx = curX + dirX[i];
            int dy = curY + dirY[i];
            if (dx >= 0 && dy >= 0 && dx < n && dy < m) {
                if (arr[dx][dy] == num && chk[dx][dy] == false) {
                    chk[dx][dy] = true;
                    cnt++;
                    que.push({ dx, dy });
                }
            }
        }
    }
    ans += (num * cnt);
}

int compareDiceAndArr(int dir, int val) {
    if (val > 0) {
        if (dir == 0) return 2;
        else if (dir == 1) return 3;
        else if (dir == 2) return 1;
        else return 0;
    }
    else if (val < 0) {
        if (dir == 0) return 3;
        else if (dir == 1) return 2;
        else if (dir == 2) return 0;
        else return 1;
    }
    else {
        return dir;
    }
}
void updateDiceState(int d) {
    int d1 = dice[1];
    int d2 = dice[2];
    int d3 = dice[3];
    int d4 = dice[4];
    int d5 = dice[5];
    int d6 = dice[6];

    if (d == 0) {
        dice[1] = d4;
        dice[4] = d6;
        dice[6] = d3;
        dice[3] = d1;
    }
    else if (d == 1) {
        dice[1] = d3;
        dice[3] = d6;
        dice[6] = d4;
        dice[4] = d1;
    }
    else if (d == 2) {
        dice[1] = d2;
        dice[2] = d6;
        dice[6] = d5;
        dice[5] = d1;
    }
    else if (d == 3) {
        dice[1] = d5;
        dice[5] = d6;
        dice[6] = d2;
        dice[2] = d1;
    }
}

int main() {
    cin >> n >> m >> k;

    for (int i = 0;i < n;i++) {
        for (int j = 0;j < m;j++) {
            cin >> arr[i][j];
        }
    }

    int x = 0; int y = 0; int d = 0;

    for (int i = 0;i < k; i++) {
        int curX = x + dirX[d];
        int curY = y + dirY[d];

        // range check
        if (curX < 0 || curY < 0 || curX >= n || curY >= m) {
            d = changeDirection(d);
            curX = x + dirX[d];
            curY = y + dirY[d];
        }

        getScore(curX, curY);
        updateDiceState(d);

        d = compareDiceAndArr(d, dice[6] - arr[curX][curY]);
        x = curX;
        y = curY;

    }

    cout << ans << "\n";
    return 0;
}