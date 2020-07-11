#include <iostream>
#include <queue>
#include <algorithm>

using namespace std;
int n,m;
//Box �迭
//distance �迭 --> ��� -1�� �ʱ�ȭ
int box[1000][1000];
int dist[1000][1000];
//direction �迭
int dirX[4]={1,0,-1,0};
int dirY[4]={0,1,0,-1};

int main(void){
    
    cin>>m>>n;
    queue<pair<int,int>> que; //��� 1�� ������ ���� ť�� �ְ�, bfs�� ������ �ȴ�...;

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

            if(curX<0||curX>=n||curY<0||curY>=m) continue; //������ ��� ���
            if(dist[curX][curY]>=0) continue; //�Ʊ� 0�ΰ� -1�� �ٲ����ϱ�
            dist[curX][curY] = dist[cur.first][cur.second] +1;
            que.push({curX,curY});
        }
    }
    int ans=-1;
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            if(dist[i][j]==-1){ //��� ���� ���� ��Ȳ�̾����� ���Ѵ�.
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