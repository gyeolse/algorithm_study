//시작점이 두 종류인 BFS
#include <iostream>
#include <queue>
#include <algorithm>
#include <string>
using namespace std;
int n,m;
//input
string board[1002];
//direction
int dirX[4]={1,0,-1,0};
int dirY[4]={0,1,0,-1};
//output
int dist1[1002][1002]; //fire
int dist2[1002][1002]; //지훈

int main(void){
    cin>>n>>m;
    for(int i=0;i<n;i++){
        fill(dist1[i],dist1[i]+m,-1);
        fill(dist2[i],dist2[i]+m,-1);
    }
    for(int i=0;i<n;i++){
        cin>>board[i];
    }
    queue<pair<int,int>> q1;
    queue<pair<int,int>> q2;

//전체를 돌면서, 배열에서 J와 F를 넣어줌.
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            if(board[i][j]=='F'){
                q1.push({i,j});
                dist1[i][j]=0;
            }
            if(board[i][j]=='J'){
                q2.push({i,j});
                dist2[i][j]=0;                
            }
        }
    }
//불
    while(!q1.empty()){
        pair<int,int> cur = q1.front(); q1.pop();
        for(int i=0;i<4;i++){
            int curX = cur.first+dirX[i];
            int curY = cur.second+dirY[i];
            //범위
            if(curX<0||curX>=n||curY<0|curY>=m) continue;
            //이미 방문해서 0보다 크거나, 벽이거나
            if(dist1[curX][curY]>=0||board[curX][curY]=='#') continue;
            dist1[curX][curY]=dist1[cur.first][cur.second]+1;
            q1.push({curX,curY});
        }
    }
//ㅈ훈
    while(!q2.empty()){
        pair<int,int> cur = q2.front(); q2.pop();
        for(int i=0;i<4;i++){
            int curX = cur.first+dirX[i];
            int curY = cur.second+dirY[i];
            if(curX<0||curX>=n||curY<0||curY>=m) {
                //범위에 벗어났다는 것은 탈출에 성공했다는 의미.
                //큐에 거리 순으로 들어가므로, 최초에 탈출한 시간을 출력하면 됨.
                cout<<dist2[cur.first][cur.second]+1;
                return 0;
            }
            if(dist2[curX][curY]>=0||board[curX][curY]=='#') continue;
            //둘의 전파시간을 조건에 추가하는 과정.
            if(dist1[curX][curY]!=-1 && dist1[curX][curY]<=dist2[cur.first][cur.second]+1) continue;

            dist2[curX][curY]=dist2[cur.first][cur.second]+1;
            q2.push({curX,curY});\
        }
    }
    cout<<"IMPOSSIBLE"; //여기까지 도달했다는 것은 탈출에 실패했다는 것을 의미한다는게 무슨소리야

} 