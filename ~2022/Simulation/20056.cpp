#include <bits/stdc++.h>
using namespace std;
int n, m, k;

int dirX[8] = { -1,-1,0,1,1,1,0,-1 };
int dirY[8] = { 0,1,1,1,0,-1,-1,-1 };

int allDirection[4] = { 0,2,4,6 };
int notDirection[4] = { 1,3,5,7 };

struct Fireball
{
    int x;
    int y;
    int massive; //질량
    int speed; //속도
    int direction;
};

vector<Fireball> fireVector;
vector<Fireball> board[55][55];

void move() {
    // 배열 일단 reset
    for(int i=1;i<=n;i++) {
        for(int j=1;j<=n;j++) {
            board[i][j].clear();
        }
    }

    // 속도 수 만큼 움직여야함
    for(int i=0;i<fireVector.size();i++) {
        int x = fireVector[i].x;
        int y = fireVector[i].y;
        int mass = fireVector[i].massive;
        int sp = fireVector[i].speed;
        int dir = fireVector[i].direction;

        // 속도 수 만큼 세팅
        int move = sp%n;
        int curX = x +  dirX[dir] * move;
        int curY = y +  dirY[dir] * move;
        // 범위 벗어났는지 체크
        if(curX > n ) curX -=n;
        if(curY > n ) curY -= n;
        if(curX < 1 ) curX += n;
        if(curY < 1) curY +=n;

        // board에 파이어볼 넣기
        board[curX][curY].push_back({curX,curY,mass,sp,dir});

        // fireball x 값 새로고침 
        fireVector[i].x = curX;
        fireVector[i].y = curY;
    }
}

void sum() {
    vector<Fireball> tempVec;

    for(int i=1;i<=n;i++) {
        for(int j=1;j<=n;j++) {
            //  
            if(board[i][j].size() == 0 ) continue;
            if(board[i][j].size() == 1) {
                tempVec.push_back(board[i][j][0]);
                continue;
            }
            

            int massSum = 0; 
            int speedSum = 0;
            int cnt = board[i][j].size();

            bool isOdd = true; bool isEven = true;

            for(int k=0;k<board[i][j].size();k++) {
                massSum += board[i][j][k].massive;
                speedSum += board[i][j][k].speed;
                // 짝수 
                if(board[i][j][k].direction % 2 == 0 ) isOdd = false; 
                // 홀수
                else isEven = false; 
            }

            int mass = massSum/5;
            int speed = speedSum/cnt;

            if(mass == 0 ) continue; // 추가

            if(isOdd == true || isEven == true ) {
                // 0,2,4,6
                for(int k = 0; k< 4;k++) {
                    tempVec.push_back({i,j,mass,speed,allDirection[k]});
                }
            }
            else {
                // 1, 3, 5, 7
                for(int k=0;k<4;k++) {
                    tempVec.push_back({i,j,mass,speed,notDirection[k]});
                }
            }
        }
    }

    fireVector = tempVec;
}


int main() {

    // 입력
    cin >> n >> m >> k; //n*n 격자에서 파이어볼 m개 발사, k번의 명령
    for (int i = 0;i < m;i++) {
        int a, b, c, d, e;
        cin >> a >> b >> c >> d >> e;
        Fireball tempFireball;
        tempFireball.x = a; tempFireball.y = b; tempFireball.massive = c; tempFireball.speed = d; tempFireball.direction = e;
        fireVector.push_back(tempFireball);
        board[a][b].push_back(tempFireball);
    }

    // k번 실행

    for (int i = 0;i < k;i++) {
        move();
        sum();
    }

    // 출력 
    int res = 0;

    for(int i =0;i<fireVector.size();i++) {
        res += fireVector[i].massive;
    }
    cout<<res<<"\n";

    return 0;
}