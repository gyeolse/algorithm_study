#include <bits/stdc++.h>
using namespace std;

int w, h;
int board[103][103]; //0이면 방문 가능, -1이면 * 벽, -2면 "C"
int visit[103][103]; 
int dirX[4] = {1,0,-1,0};
int dirY[4] = {0,1,0,-1};

bool isStartPosition = true;
pair<int,int> startPosition;
pair<int,int> destPosition;

bool isAvailable(int X,int Y) {
    if(X < 0 || Y < 0 || X >= h || Y >= w ) return false;
    if(board[X][Y] == -1 ) return false;
    //if(board[X][Y] == -1 || visit[X][Y] !=0) return false 가 틀린 이유 ? 
    return true;
}
int main() {
    ios::sync_with_stdio(false); cin.tie(NULL);
    cin>>w>>h; //7 8
    for(int i=0;i<h;i++) {
        string s;
        cin>>s;
        for(int j=0;j<w;j++){
            if(s[j] == '*') board[i][j] = -1; //벽
            if(s[j] == '.') board[i][j] = 0; //방문 가능
            if(s[j] == 'C') {
                board[i][j] = -2; //C 설정. 시작점과 종료점 설정
                if(isStartPosition) {
                    startPosition = {i,j};
                    isStartPosition = false;                    
                } else {
                    destPosition = {i,j};
                }
            }  
        }
    }

    queue<pair<int,int>> que;
    que.push(startPosition); 
//    visit[startPosition.first][startPosition.second] = 1;

    while(!que.empty()) {
        pair<int,int> cur = que.front(); que.pop();
        for(int dir=0;dir<4;dir++) {
            int curX = cur.first + dirX[dir];
            int curY = cur.second + dirY[dir];
            /* 
            isAvailable에 visit[curX][curY] 까지 때려넣으면 틀리는 이유 
            1. 일직선 방향에 이미 방문한 경우는 뛰어 넘고, 그 뒤를 확인해야함
            2. 그냥 무작정 방문하지 않은 경우를 pass 해버리면 다음 90도 회전으로 넘어가버림
            3. 그래서 확인한 점 뒤를 확인하지 못하게 되므로 틀리게 되는 것.
            */
            while(isAvailable(curX,curY)) { //true 경우에만
                if(visit[curX][curY] == 0) {
                    visit[curX][curY] = visit[cur.first][cur.second] + 1;                
                    que.push({curX,curY});
                }
                curX += dirX[dir]; curY +=dirY[dir];                                    
            }
        }
    }

    // for(int i=0;i<h;i++) {
    //     for(int j=0;j<w;j++){
    //         cout<<visit[i][j]<<" ";
    //     }
    //     cout<<endl;
    // }
    
    // -1하는 이유 : 맨 처음에 거울이 필요하지 않을떄도 1로 카운트 되니까 
    //1을 빼주어야함.
    cout<<visit[destPosition.first][destPosition.second]-1<<endl;
    return 0;
}