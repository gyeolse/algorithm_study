#include <bits/stdc++.h>
using namespace std;

char board[11][11];
int n, m;
int dirX[4] = { -1,1,0,0 };
int dirY[4] = { 0,0,1,-1 };

pair<int, int> redBall;
pair<int, int> blueBall;

void input();
int ans = 987654321;

int checkDirection(int n) {
    if (n == 0) return 1;
    else if (n == 1) return 0;
    else if (n == 2) return 3;
    else return 2;
}

int checkDistance(int curX, int curY, int nextX, int nextY) {
    return abs(curX - nextX) + abs(curY - nextY);
}

void func(int redX, int redY, int blueX, int blueY, int cnt, int dir) {
    if (cnt > 10) return;
    if (cnt >= ans) return;
    bool redFlag = false; bool blueFlag = false;

    // 빨간구슬 체크
    int curRedX = redX + dirX[dir];
    int curRedY = redY + dirY[dir];

    while (1) {
        if (board[curRedX][curRedY] == '#') break;
        if (board[curRedX][curRedY] == 'O') {
            redFlag = true;
            break;
        }

        curRedX += dirX[dir];
        curRedY += dirY[dir];
    }

    // while문에서 탈출하기 바로 전 상황으로 돌리기 
    curRedX -= dirX[dir]; curRedY -= dirY[dir];

    // 파란구슬 체크 
    int curBlueX = blueX + dirX[dir];
    int curBlueY = blueY + dirY[dir];

    while (1) {
        if (board[curBlueX][curBlueY] == '#') break;
        if (board[curBlueX][curBlueY] == 'O') {
            blueFlag = true;
            break;
        }

        curBlueX += dirX[dir];
        curBlueY += dirY[dir];
    }
    curBlueX -= dirX[dir]; curBlueY -= dirY[dir];

    // 상태 체크
    if (blueFlag == true) {
        return;
    }
    else {
        if (redFlag == true) {
            ans = min(ans, cnt);
            return;
        }
    }
    if (redFlag == true) {
        ans = min(ans, cnt);
        return;
    }
    else if (blueFlag == true) {
        return;
    }

    // 다음을 위해서 
    if (curRedX == curBlueX && curRedY == curBlueY) {
        // 더 많이 이동한 구슬을 한 칸 땡겨야 함. 
        int redDistance = checkDistance(redX, redY, curRedX, curRedY);
        int blueDistance = checkDistance(blueX, blueY, curBlueX, curBlueY);

        // blue가 더 많이 이동
        if (redDistance > blueDistance) {
            curRedX -= dirX[dir];
            curRedY -= dirY[dir];
        }
        // red가 더 많이 이동
        else {
            curBlueX -= dirX[dir];
            curBlueY -= dirY[dir];
        }
    }

    // 다음으로 이동 
    for (int i = 0;i < 4;i++) {
        // 현재 방향 X
        if (i == dir) continue;
        // 현재 방향의 역방향이면 X
        if (i == checkDirection(dir)) continue;

        func(curRedX, curRedY, curBlueX, curBlueY, cnt + 1, i);
    }
}

int main() {
    cin >> n >> m;
    input();

    for (int dir = 0;dir < 4;dir++) {
        int redX = redBall.first;
        int redY = redBall.second;

        int blueX = blueBall.first;
        int blueY = blueBall.second;
        func(redX, redY, blueX, blueY, 1, dir); //현재 방향도 포함시키기
    }

    if (ans == 987654321 || ans > 10) cout << -1 << "\n";
    else cout << ans << "\n";
    return 0;
}

void print() {
    for (int i = 0;i < n;i++) {
        for (int j = 0;j < m;j++) {
            cout << board[i][j] << " ";
        }
        cout << endl;
    }
}
void input() {
    for (int i = 0;i < n;i++) {
        string s; cin >> s;
        for (int j = 0;j < s.size();j++) {
            if (s[j] == '.') {
                board[i][j] = '.';
            }
            else if (s[j] == '#') {
                board[i][j] = '#';
            }
            else if (s[j] == 'O') {
                board[i][j] = 'O';
            }
            else if (s[j] == 'R') {
                board[i][j] = '.';
                redBall = { i,j };
            }
            else if (s[j] == 'B') {
                board[i][j] = '.';
                blueBall = { i,j };
            }
        }
    }
}