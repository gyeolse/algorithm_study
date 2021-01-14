#include <iostream>
#include <queue>
#include <algorithm>
#include <vector>
using namespace std;
int board[101][101];
int dist[101][101];
int n;
int dirX[4] = {1,0,-1,0};
int dirY[4] = {0,1,0,-1};
int m; //MAX
vector<int> vec; //���� MAX ���� �ֱ� ���� �迭
int main(void){
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin>>n;
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            cin>>board[i][j];
            if(m<board[i][j]){
                m = board[i][j]; //�ִ밪
            }
        }
    }

    //count
    for(int depth=0;depth<=m;depth++){
        for(int i=0;i<n;i++){
            fill(dist[i],dist[i]+n,-1);
        }        
        int cnt=0;
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                if(dist[i][j]!=-1) continue;
                if(board[i][j]<=depth) continue;

                queue<pair<int,int>> que;
                dist[i][j]=0;
                que.push({i,j});
                cnt++;
                while(!que.empty()){
                    pair<int,int> cur = que.front(); que.pop();
                    for(int k=0;k<4;k++){
                        int curX = cur.first + dirX[k];
                        int curY = cur.second + dirY[k];
                        //����
                        if(curX<0||curX>=n||curY<0||curY>=n) continue;
                        //�湮����. <=�� �ƴ϶� <��� �ؼ� ��� Ʋ���� �������� ����
                        if(dist[curX][curY]!=-1 || board[curX][curY]<=depth) continue;
                        dist[curX][curY] = 1;
                        que.push({curX,curY});
                    }
                }
            }
        }
        vec.push_back(cnt);        
    }
    cout<<*max_element(vec.begin(),vec.end());
    return 0;
}