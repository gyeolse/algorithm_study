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

void func(int redX, int redY, int blueX, int blueY, int cnt, int i) {
    //1. cnt가 10 초과면 불가 
    if (cnt > 10) return;

    //2. 현재 저장된 값보다, 더 크면 불가
    if (cnt >= ans) return;

    bool blueFlag = false;
    bool redFlag = false;
y
    //3. 현재 구슬 위치
    int curRedX = redX + dirX[i];    
    int curRedY = redY + dirY[i];
    //4. 방향으로 최대한 빨간 공 이동 
    while (1) {
        //벽을 만나면 break;
        if (board[curRedX][curRedY] == '#') break;
        if (board[curRedX][curRedY] == 'O') {
            redFlag = true;
            break;
        }
        curRedX += dirX[i]; 
        curRedY += dirY[i];
    }
    // 위치를 한 칸 뒤로 이동
    curRedX -= dirX[i]; curRedY -= dirY[i];

    int curBlueX = blueX + dirX[i];    int curBlueY = blueY + dirY[i];
    //5. 방향으로 최대한 파란 공 이동
    while (1) {
        if (board[curBlueX][curBlueY] == '#') break;
        if(board[curBlueX][curBlueY] =='O') {
            blueFlag = true;
            break;
        }
        curBlueX += dirX[i]; curBlueY += dirY[i];
    }
    curBlueX -= dirX[i]; curBlueY -= dirY[i];

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

    // 만약 같은 위치에 존재한다면,
    if (curRedX == curBlueX && curRedY == curBlueY) {
        // 더 많이 이동한 구슬 찾기 
        int redDistance = checkDistance(redX, redY,curRedX, curRedY);
        int blueDistance = checkDistance(blueX, blueY,curBlueX, curBlueY);

        // 더 많이 이동한 구슬을 한 칸 땡겨줌
        // 파란 공이 더 많이 이동한 경우
        if (redDistance > blueDistance) {
            curRedX -= dirX[i];
            curRedY -= dirY[i];
        }
        // red가 더 많이 이동
        else {
            curBlueX -= dirX[i];
            curBlueY -= dirY[i];
        }
    }

    // 7. 다음 위치로 이동
    for (int dir = 0;dir < 4;dir++) {
        // 만약 현재와 같은 방향이면 pass
        if (dir == i) continue;
        // 현재와 역 방향이라면 pass
        if (dir == checkDirection(i)) continue;

        // 그 외 위치로 이동
        func(curRedX, curRedY, curBlueX, curBlueY, cnt + 1, dir);
    }
}

void input() {
    cin >> n >> m;
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

void output() {
    if(ans== 987654321 || ans >10) {
        cout<<0<<"\n";
    }
    else {
        cout<<1<<"\n";
    }
}

int main() {
    input();

    for (int x = 0;x < 4;x++) {
        func(redBall.first, redBall.second, blueBall.first, blueBall.second, 1, x);
    }

    output();
    return 0;
}
