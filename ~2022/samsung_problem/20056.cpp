#include <bits/stdc++.h>
using namespace std;

// Fireball. x, y, m, d, s
struct Fireball {
    int x;
    int y;
    int massive; //질량
    int speed; //속도
    int direction;
};
// Fireball Vector
vector<Fireball> fireballVector;
vector<Fireball> board[60][60];

// direction 
int dirX[8] = { -1,-1,0,1,1,1,0,-1 };
int dirY[8] = { 0,1,1,1,0,-1,-1,-1 };

int okDirection[4] = { 0, 2, 4, 6 };
int notDirection[4] = { 1, 3, 5, 7 };

int n, m, k;

/////////////////////////////////////////////////

void moveFireball() {
    // reset
    for (int i = 1;i <= n;i++) {
        for (int j = 1;j <= n;j++) {
            board[i][j].clear();
        }
    }

    // 일단 움직이기 
    for (int i = 0;i < fireballVector.size(); i++) {
        int x = fireballVector[i].x;
        int y = fireballVector[i].y;
        int m = fireballVector[i].massive;
        int dir = fireballVector[i].direction;
        int sp = fireballVector[i].speed;

        // 움직일 수 있는지 확인 
        int mv = sp % n;
        int curX = x + dirX[dir] * mv;
        int curY = y + dirY[dir] * mv;

        if (curX > n) curX -= n;
        if (curY > n) curY -= n;
        if (curX < 1) curX += n;
        if (curY < 1) curY += n;

        // board에 넣기
        board[curX][curY].push_back({ curX, curY, m, sp, dir });

        // fireball 새로고침
        fireballVector[i].x = curX;
        fireballVector[i].y = curY;
    }
}

void sumFireball() {
    vector<Fireball> tempVec;

    for (int i = 1;i <= n;i++) {
        for (int j = 1;j <= n;j++) {
            if (board[i][j].size() == 0) continue;
            if (board[i][j].size() == 1) {
                tempVec.push_back(board[i][j][0]); // 어차피 하나 있음.
                continue;
            }

            int massSum = 0;
            int speedSum = 0;
            int cnt = board[i][j].size();

            bool isOdd = true; bool isEven = true;

            for (int k = 0;k < board[i][j].size(); k++) {
                massSum += board[i][j][k].massive;
                speedSum += board[i][j][k].speed;

                if (board[i][j][k].direction % 2 == 0) isOdd = false;
                else isEven = false;
            }

            int mass = massSum / 5;
            int speed = speedSum / cnt;

            if (mass == 0) continue;

            if (isOdd == true || isEven == true) {
                for (int k = 0;k < 4;k++) {
                    tempVec.push_back({ i,j,mass,speed, okDirection[k] });
                }
            }
            else {
                for (int k = 0;k < 4;k++) {
                    tempVec.push_back({ i,j,mass,speed, notDirection[k] });
                }
            }
        }
    }

    fireballVector = tempVec;
}

int main() {

    // input
    cin >> n >> m >> k;

    for (int i = 0;i < m;i++) {
        int a, b, c, d, e;
        cin >> a >> b >> c >> d >> e;
        Fireball fb;
        fb.x = a;
        fb.y = b;
        fb.massive = c;
        fb.speed = d;
        fb.direction = e;
        fireballVector.push_back(fb);
        board[a][b].push_back(fb);
    }

    // move, sum
    for (int i = 0;i < k;i++) {
        moveFireball();
        sumFireball();
    }

    // output
    int res = 0;

    for (int i = 0;i < fireballVector.size();i++) {
        res += fireballVector[i].massive;
    }

    cout << res << "\n";
    return 0;
}