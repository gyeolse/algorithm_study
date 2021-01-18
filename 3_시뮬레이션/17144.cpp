#include <bits/stdc++.h>
using namespace std;

int r, c, t; //t는 초
pair<int, int> top_purifier;
pair<int, int> bottom_purifier;
bool chkLoc = false;
int board[50][50]; //크기

int dustSize = 0; //미세먼지 양

int dirX[4] = {1,0,-1,0};
int dirY[4] = {0,1,0,-1};

//미세먼지 확산 함수 
void dustSpread() {
    queue<pair<int,int>> que;

    //1. 현재 보드와 같은 사이즈로 생성하고, 미세먼지 있는 위치를 큐에 넣기
    int tempBoard[50][50];
    for(int i=0;i<r;i++){
        for(int j=0;j<c;j++){
            tempBoard[i][j] = board[i][j];
            if(board[i][j] > 0) que.push({i,j});
        }
    }

    //2. 미세먼지 확산 실행
    while(!que.empty()){
        auto cur = que.front(); que.pop();
        //몇 개에 확산시킬지 셀 변수
        int cntArea = 0;

        //1) 공기청정기가 있으면 || 범위 밖이면 해당 노드는 넘어간다. 
        for(int dir=0;dir<4;dir++) {
            int curX=cur.first + dirX[dir];
            int curY=cur.second + dirY[dir];
            if(board[curX][curY] == -1 ) continue;
            if(curX<0 || curY<0 || curX>=r || curY>=c) continue;
            cntArea++;
        }
        //2) 카운팅된 만큼 값을 설정해주고, 변경해준다.
        int curDust = board[cur.first][cur.second];
        int blowingDust = curDust/5;

        int modifyDust = curDust - (blowingDust*cntArea);
        tempBoard[cur.first][cur.second] = modifyDust;
        //3) 불어온 먼지를 해당 위치에 더해!! 준다. (여러 먼지가 날아올 수 있음.)
        for(int dir=0;dir<4;dir++) {
            int curX=cur.first + dirX[dir];
            int curY=cur.second + dirY[dir];
            if(board[curX][curY] == -1 ) continue;
            if(curX<0 || curY<0 || curX>=r || curY>=c) continue;
            tempBoard[curX][curY] = blowingDust;
        }
    }
    //마지막. 임시배열과 현재보드와 swap
    for(int i=0;i<r;i++){
        for(int j=0;j<c;j++){
            board[i][j] = tempBoard[i][j];
        }
    }

    return;
}

//공기청정기 구동 함수
void operate_purifier() {

}

int main() {
    //1. 입력 
    cin >> r >> c >> t;
    for (int i = 0;i < r;i++) {
        for (int j = 0;j < c;j++) {
            cin >> board[i][j];
            if (board[i][j] == -1 && chkLoc == false) {
                top_purifier = { i,j };
                chkLoc = true;
            }
            if (board[i][j] == -1 && chkLoc == true) {
                bottom_purifier = { i,j };
            }
        }
    }
    //2. t초 동안 진행
    while(t--) {

        //1. 미세먼지 확산 함수
        dustSpread();

        //2. 공기청정기 함수
        operate_purifier();
    }

    //3. 미세먼지 출력
    for(int i=0;i<r;i++){
        for(int j=0;j<c;j++){
            if(board[i][j] > 0 ) {
                dustSize++;
            }
        }
    }
    cout<<dustSize<<"\n";
    return 0;
}