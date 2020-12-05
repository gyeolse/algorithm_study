#include <bits/stdc++.h>
using namespace std;

int board[101][101]; //입력받는 배열
int visit[101][101]; //-1은 외부공기, 0은 걍 공기, 

int dirX[4] = {1,0,-1,0};
int dirY[4] = {0,1,0,-1};

int n,m;

int loopCnt;
int cheezeCnt;

void bfs_first() {
    //step1. 외부공기, 내부공기 구분
    queue<pair<int,int>> que;
    que.push({0,0}); //0,0을 넣고, 좌표를 돌면서, board[i][j] = 1 이면 pass, 0이면 -1로 visit을 세팅해줌.
    visit[0][0] = -1;
    while(!que.empty()) { 
        pair<int,int> cur = que.front(); que.pop();
        for(int dir=0;dir<4;dir++) {
            int curX = cur.first + dirX[dir];
            int curY = cur.second + dirY[dir];
            //1. board[curX][curY] = 1
            if(board[curX][curY]==1 || visit[curX][curY] != 0) continue;
            if(curX<0|| curY <0 || curX>=n || curY >=m) continue;
            visit[curX][curY] = -1;
            que.push({curX,curY});
        }
    }
}

void bfs_second() {
        int board2[101][101]; //임시로 선언
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(board[i][j] == 1 && visit[i][j]==0) {
                    queue<pair<int,int>> que; 
                    que.push({i,j});
                    while(!que.empty()) {
                        pair<int,int> cur = que.front(); que.pop();
                        for(int dir=0;dir<4;dir++){
                            int curX = cur.first + dirX[dir];
                            int curY = cur.second + dirY[dir];
                            if(curX>=n || curY >=m || curX<0 || curY<0) continue;
                            if(visit[curX][curY] == -1 && board[curX][curY] == 0) { //'c'에 해당함 4군데중 하나라도 공기가 있는 상태   
                                board2[cur.first][cur.second] = 0; //1-> 0
                                visit[cur.first][cur.second] = 1; 
                                cheezeCnt++; //cheeze의 갯수를 더함
                                break;
                            }
                            if(visit[curX][curY] == 0 && board[curX][curY]==1) { //큐에 넣어줘야하는 1을 발견한 상태
                                board2[curX][curY] = 1;
                                visit[curX][curY] = 1;
                                que.push({curX,curY});                            
                            }
                        }
                    }
                }
            }
        }

        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                board[i][j] = board2[i][j];
            }
        }
}

bool check() {
    for(int i=0;i<n;i++) {
        for(int j=0;j<m;j++) {
            if(board[i][j] == 1) return false;
        }
    }
    return true;
}
int main() {
    cin>>n>>m;
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            cin>>board[i][j];
        }
    }

    while(1) {
        cheezeCnt = 0;
        loopCnt++;
        bfs_first();
        bfs_second();

        if(check() == true) {
            break;
        }
        memset(visit,0,sizeof(visit));
    }
    cout<<loopCnt<<"\n";
    cout<<cheezeCnt<<"\n";
}