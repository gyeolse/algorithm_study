#include <bits/stdc++.h>
#define endl '\n'
#define MAX 50
using namespace std;

int board[MAX][MAX];
int r, c, t;
int dirX[4] = { 1,0,-1,0 };
int dirY[4] = { 0,1,0,-1 };
vector<pair<int,int>> purifierDirection;

// 함수 
void input();
void print();
bool isAvailable(int x, int y);

void dustExpansion() {
    //1. copyBoard 선언, bfs용 queue 선언 
    queue<pair<int,int>> que;

    //2. x,y 좌표에서 갈 수 있는 위치를 count 
    for(int i=0;i<r;i++) {
        for(int j=0;j<c;j++) {
            if(board[i][j] != -1 && board[i][j] > 0 ) {
                que.push({ i , j });
            }
        }
    }

    int copyBoard[MAX][MAX];
    memset(copyBoard,0,sizeof(copyBoard));

    //3.해당 위치에서 갈 수 있는 방향으로, 이동
    while(!que.empty()) {
        auto cur = que.front(); que.pop();

        //3-1. 현재 좌표에서 갈 수 있는 방향을 탐색         
        int cnt = 0;
        vector<pair<int,int>> availableLocation;

        for(int dir=0;dir<4;dir++) {
            int curX = dirX[dir] + cur.first;
            int curY = dirY[dir] + cur.second;
            if(board[curX][curY] == -1) continue;
            if(!isAvailable(curX,curY)) continue;
            cnt++;
            availableLocation.push_back({curX,curY});
        }

        //3-2 값 계산 
        int windDust = board[cur.first][cur.second]/5;
        int curDust = board[cur.first][cur.second] - (windDust*cnt);

        //3-3 현재 좌표에서 갈 수 있는 애들 값 -> copyBoard로 설정
        for(int i=0;i<availableLocation.size();i++) {
            int x = availableLocation[i].first;
            int y = availableLocation[i].second;

            copyBoard[x][y] += windDust;
        }
        copyBoard[cur.first][cur.second] += curDust;
    }

    //4.모두 이동 후, copyboard와 현재 board와 갈아치우기
    for(int i=0;i<r;i++) {
        for(int j=0;j<c;j++) {
            board[i][j] = copyBoard[i][j];
        }
    }
}

void purifierOperate() {
    // 1. copyBoard 만들기 
    int copyBoard[MAX][MAX];

    pair<int,int> upPurifier = purifierDirection[0];
    pair<int,int> downPurifier = purifierDirection[1];

    // 2. 직접 for문 돌면서 이동 시켜서 copyBoard에 넣기 
    int upX = upPurifier.first; int upY = upPurifier.second;

    // 1. 공기청정기 -> 0,0까지 OK
    for(int i=upX-1;i>0;i--) {
        board[i][0] = board[i-1][0];
    }

    // 2. 윗 줄 -> OK 
    for(int i=0;i<c-1;i++) {
        board[0][i] = board[0][i+1];
    }

    // 3. 세로줄 OK
    for(int i=1;i<=upX;i++) {
        board[i-1][c-1] = board[i][c-1];
    }

    //4. 제일 아랫줄
    for(int i=c-1;i>0;i--) {
        board[upX][i] = board[upX][i-1];
    }
    // 추가해야함
    board[upX][1] = 0;

    //2-2. 아래 방향 
    int downX = downPurifier.first; int downY = downPurifier.second;

    for(int i = downX + 1;i<r-1;i++) {
        board[i][0] = board[i+1][0];
    }

    for(int i=0;i<c-1;i++) {
        board[r-1][i] = board[r-1][i+1];
    }

    for(int i=r-1;i >=downX;i--) {
        board[i][c-1] = board[i-1][c-1];
    }

    for(int i=c-1;i > 1;i--) {
        board[downX][i] = board[downX][i-1];
    }
    board[downX][1] = 0;


    // 3. 공기청정기 위치 재설정
    for(int i=0;i<purifierDirection.size();i++) {
        board[purifierDirection[i].first][purifierDirection[i].second] = -1;
    }
}

int main() {
    input();
    while (t--) {
        // 1. 해당 위치에서 확산 하도록 함
        dustExpansion();
        // 2. 공기청정기 작동 
        purifierOperate();
    }
    // 4. TEST value 확인
    print();
    return 0;
}

void input() {
    cin >> r >> c >> t;

    for (int i = 0;i < r;i++) {
        for (int j = 0;j < c;j++) {
            cin >> board[i][j];
            if(board[i][j]==-1) {
                purifierDirection.push_back({i,j});
            }
        }
    }
}

bool isAvailable(int x, int y) {
    if(x < 0 || y < 0 || x>=r || y>=c) return false;
    return true;
}

void print() {
    // cout<<"============test====="<<endl;
    int ans = 0;
    for(int i=0;i<r;i++) {
        for(int j=0;j<c;j++) {
            if(board[i][j] != -1 && board[i][j] > 0) {
                ans += board[i][j];
            }
            // cout<<board[i][j]<<" ";
        }
        // cout<<endl;
    }
    cout<<ans<<endl;
}