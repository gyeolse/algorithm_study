//�������� �� ������ BFS
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
int dist2[1002][1002]; //����

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

//��ü�� ���鼭, �迭���� J�� F�� �־���.
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
//��
    while(!q1.empty()){
        pair<int,int> cur = q1.front(); q1.pop();
        for(int i=0;i<4;i++){
            int curX = cur.first+dirX[i];
            int curY = cur.second+dirY[i];
            //����
            if(curX<0||curX>=n||curY<0|curY>=m) continue;
            //�̹� �湮�ؼ� 0���� ũ�ų�, ���̰ų�
            if(dist1[curX][curY]>=0||board[curX][curY]=='#') continue;
            dist1[curX][curY]=dist1[cur.first][cur.second]+1;
            q1.push({curX,curY});
        }
    }
//����
    while(!q2.empty()){
        pair<int,int> cur = q2.front(); q2.pop();
        for(int i=0;i<4;i++){
            int curX = cur.first+dirX[i];
            int curY = cur.second+dirY[i];
            if(curX<0||curX>=n||curY<0||curY>=m) {
                //������ ����ٴ� ���� Ż�⿡ �����ߴٴ� �ǹ�.
                //ť�� �Ÿ� ������ ���Ƿ�, ���ʿ� Ż���� �ð��� ����ϸ� ��.
                cout<<dist2[cur.first][cur.second]+1;
                return 0;
            }
            if(dist2[curX][curY]>=0||board[curX][curY]=='#') continue;
            //���� ���Ľð��� ���ǿ� �߰��ϴ� ����.
            if(dist1[curX][curY]!=-1 && dist1[curX][curY]<=dist2[cur.first][cur.second]+1) continue;

            dist2[curX][curY]=dist2[cur.first][cur.second]+1;
            q2.push({curX,curY});\
        }
    }
    cout<<"IMPOSSIBLE"; //������� �����ߴٴ� ���� Ż�⿡ �����ߴٴ� ���� �ǹ��Ѵٴ°� �����Ҹ���

} 