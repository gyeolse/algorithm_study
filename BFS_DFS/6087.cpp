//레이저통신
#include <bits/stdc++.h>
using namespace std;
int w,h;
int board[103][103];
int visit[103][103];
int dirX[4] = {1,0,-1,0};
int dirY[4] = {0,1,0,-1};

int main() {
    cin>>w>>h; //7 8
    string s;
    //input
    for(int i=0;i<h;i++) {
        cin>>s;
        for(int j=0;j<w;j++) {
            if(s[j] == '.') board[i][j] = 0; // . 빈칸
            if(s[j] == '*') board[i][j] = -1; //*. 벽
            if(s[j] == 'C') board[i][j] = -2; //C. 레이저로 연결해야 하는 칸
        }        
    }

    pair<int,int> startPosition;
    pair<int,int> destPosition;
    bool chk = false;

    for(int i=0;i<h;i++){
        for(int j=0;j<w;j++) {
            if(board[i][j]==-2){
                if(chk == false){
                    startPosition.first = i;
                    startPosition.second = j;
                    chk = true;
                } else {
                    destPosition.first = i;
                    destPosition.second = j;
                }
            }
        }
    }

    queue<pair<int,int>> que;
    que.push(startPosition);

    while(!que.empty()) {
        pair<int,int> cur = que.front(); que.pop();
        for(int dir=0;dir<4;dir++) {
            int curX = cur.first + dirX[dir];
            int curY = cur.second + dirY[dir];
            // 조건을 충족하지 못할 때 까지 일단 쭉 간다 -> 조건 충족못하면 탈출. 다음 좌표로 이동
            while(curX >= 0 && curY >= 0 && curX < h && curY <w && board[curX][curY] !=-1) {
                if(visit[curX][curY] == 0) {
                    //1. 
                    visit[curX][curY] = visit[cur.first][cur.second] + 1;
                    que.push({curX,curY});
                }
                curX += dirX[dir];
                curY += dirY[dir];
            }
        }
    }

    for(int i=0;i<h;i++) {
        for(int j=0;j<w;j++) {
            cout<<visit[i][j] <<" ";
        }
        cout<<endl;
    }
    cout<<visit[destPosition.first][destPosition.second]-1<<"\n";

}