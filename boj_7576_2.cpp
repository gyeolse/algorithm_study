#include <iostream>
#include <queue>
#include <algorithm>

using namespace std;
int n,m;
//Box 배열
//distance 배열 --> 모두 -1로 초기화
int box[1000][1000];
int dist[1000][1000];
//direction 배열
int dirX[4]={1,0,-1,0};
int dirY[4]={0,1,0,-1};

int main(void){
    
    cin>>m>>n;
    queue<pair<int,int>> que; //모든 1인 정점에 대해 큐에 넣고, bfs를 돌리면 된다...;

    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            cin>>box[i][j];
            if(box[i][j]==1){
                que.push({i,j});
            }
            if(box[i][j]==0){
                dist[i][j]=-1;
            }
        }
    }

    while(!que.empty()){
        pair<int,int> cur = que.front(); que.pop();
        for(int i=0;i<4;i++){
            int curX = cur.first + dirX[i];
            int curY = cur.second + dirY[i];

            if(curX<0||curX>=n||curY<0||curY>=m) continue; //범위가 벗어난 경우
            if(dist[curX][curY]>=0) continue; //아까 0인건 -1로 바꿨으니까
            dist[curX][curY] = dist[cur.first][cur.second] +1;
            que.push({curX,curY});
        }
    }
    int ans=-1;
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            if(dist[i][j]==-1){ //모두 익지 못한 상황이었음을 뜻한다.
                cout<<-1;
                return 0;
            }
            int temp = dist[i][j];
            ans = max(ans,temp);
        }
    }

    cout<<ans;
    return 0;
}