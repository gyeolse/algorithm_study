#include <iostream>
#include <queue>
#include <string>
#include <tuple>
using namespace std;
string board[1001]; //�Ÿ� ���
int dist[1001][1001][2]; //�Ÿ�. flag�� ���� ������ ���Խ�Ŵ.
int dirX[4]={1,0,-1,0};
int dirY[4]={0,1,0,-1};
int n,m;

int main(void){
    cin>>n>>m;
    for(int i=0;i<n;i++){
        cin>>board[i];
    }
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            fill(dist[i][j],dist[i][j]+2,-1);
        }
    }

    queue <pair<pair<int,int>,int>> que;
    que.push(make_pair(make_pair(0,0),0));
    dist[0][0][0]=0;

    while(!que.empty()){
        pair<pair<int,int>,int> cur = que.front(); que.pop();
        if(cur.first.first==n-1 && cur.first.second==m-1){
            cout<<dist[cur.first.first][cur.first.second][cur.second]+1;
            return 0;
        }
        for(int i=0;i<4;i++){
            int curX = cur.first.first + dirX[i];
            int curY = cur.first.second + dirY[i];
            int curZ = cur.second;
            //����
            if(curX<0||curX>=n||curY<0||curY>=m) continue;
            if(dist[curX][curY][curZ]!=-1) continue; //�湮���� O
            if(board[curX][curY]=='0'){
                dist[curX][curY][curZ] = dist[cur.first.first][cur.first.second][cur.second]+1;
                que.push(make_pair(make_pair(curX,curY),curZ));
//                que.push({curX,curY,curZ});
            }
            if(board[curX][curY]=='1'&&curZ==0){
                //�̶��� �ν������! �׸��� �̶����ʹ� ������ z�� 1��.                
                dist[curX][curY][1] = dist[cur.first.first][cur.first.second][cur.second]+1;
                que.push(make_pair(make_pair(curX,curY),1));
            }
        }

        if(que.size()==0){
            cout<<-1<<endl;
            return 0;
        }
    }
    return 0;
}