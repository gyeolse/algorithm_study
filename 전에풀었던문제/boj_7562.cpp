#include <iostream>
#include <algorithm>
#include <queue>
using namespace std;
int board[300][300]; //
int dirX[8] = {2,1,-1,-2,-2,-1,1,2};
int dirY[8]= {1,2,2,1,-1,-2,-2,-1};
int n,len,start_x,start_y,last_x,last_y;
int dist[300][300]; 


int main(void){
    cin>>n;
    for(int i=0;i<n;i++){
        cin>>len; //체스판 한 변의 길이
        cin>>start_x>>start_y; 
        cin>>last_x>>last_y;        
        for(int j=0;j<len;j++){
            fill(dist[j],dist[j]+len,-1);
        }
//queue
        queue<pair<int,int>> que;
        que.push({start_x,start_y});
        dist[start_x][start_y]=0;
        while(!que.empty()){
            pair<int,int> cur = que.front(); que.pop();
            for(int dir=0;dir<8;dir++){
                int curX = cur.first + dirX[dir];
                int curY = cur.second + dirY[dir];
                if(curX<0||curX>=len||curY<0||curY>=len) continue;
                if(dist[curX][curY]!=-1) continue;
                dist[curX][curY] = dist[cur.first][cur.second] + 1;
                que.push({curX,curY});
            }
        }
        cout<<dist[last_x][last_y]<<"\n";
    }
    return 0;
}