#include <bits/stdc++.h>
using namespace std;
//배열 선언
bool visit[501][501];
int board[501][501];
//좌표 선언
int dirX[4] = {1,0,-1,0};
int dirY[4] = {0,1,0,-1};

//input 값.
int n = 7;
int main(){
    queue<pair<int,int>> que; //que 선언
    visit[0][0] = 1; //처음 시작점을 방문했으므로, 1로 세팅
    que.push({0,0});  //que에 넣음. 

    while(!que.empty()){
        pair<int, int> cur = que.front(); que.pop(); //current를 queue의 front로 설정하고 queue를 pop.
        cout<<"("<<cur.first<<","<<cur.second<<") ->";
        for(int dir=0;dir<4;dir++){
            int nx=cur.first+dirX[dir];
            int ny=cur.second+ dirY[dir];
            if(nx<0||nx>=n||ny<0||ny>=n) continue; //범위 초과 확인. 범위 안맞으면 PASS
            if(visit[nx][ny] || board[nx][ny] != 1) continue; //visit[nx][ny]가 1이거나, board[nx][ny]가 1이 아니면, PASS
            //만족하는 경우, visit 처리하고, 큐에 넣기 
            visit[nx][ny] = true;
            que.push({nx,ny});
        }
    }
    return 0;
} 
