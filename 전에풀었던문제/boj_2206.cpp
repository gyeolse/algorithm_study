#include <iostream>
#include <queue>
#include <string>
using namespace std;
string board[1001]; //거리 출력
int dist[1001][1001]; //거리
int dirX[4]={1,0,-1,0};
int dirY[4]={0,1,0,-1};
int n,m;
int breakable = 0;
int main(void){
    cin>>n>>m;
    for(int i=0;i<n;i++){
        cin>>board[i];
    }
    for(int i=0;i<n;i++){
        fill(dist[i],dist[i]+m,-1);
    }
    queue <pair<int,int>> que;
    que.push({0,0});
    dist[0][0]=0;

    while(!que.empty()){
        pair<int,int> cur = que.front(); que.pop();
        for(int i=0;i<4;i++){
            int curX = cur.first + dirX[i];
            int curY = cur.second + dirY[i];
            //범위
            if(curX<0||curX>=n||curY<0||curY>=m) continue;
            if(dist[curX][curY]!=-1) continue; //방문한적 O
            if(breakable == 0 && board[curX][curY]=='1'){
                int isable= 0;
                for(int j=0;j<4;j++){
                    int nextX = curX + dirX[i];
                    int nextY = curY + dirY[i];
                    if(nextX<0||nextX>=n||nextY<0||nextY>=m) continue;
                    if(dist[nextX][nextY]!=-1) continue;
                    if(board[nextX][nextY]!='0') continue;
                    isable=1;
                }
                if(isable==1){
                    dist[curX][curY] = dist[cur.first][cur.second]+1;
                    que.push({curX,curY});
                    breakable++;
                    isable=0;
//                    cout<<"("<<curX<<","<<curY<<")"<<endl;
                }
            }
            else if(board[curX][curY]=='0'){
                que.push({curX,curY});
                dist[curX][curY] = dist[cur.first][cur.second]+1;
            }
            //방문
            //0일때만 방문하지만, 1일경우 --> breakable? --> 다시 그 노드의 사방을 탐색
        }
    }
    if(dist[n-1][m-1]!=-1){
        cout<<dist[n-1][m-1]+1<<endl;
    }
    else{
        cout<<dist[n-1][m-1]<<endl;
    }
    return 0;
}