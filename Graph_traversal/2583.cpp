#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>

using namespace std;

int n,m,k;
int visit[110][110];
int board[110][110];

int dirX[4] = {1,0,-1,0};
int dirY[4] = {0,1,0,-1};
int cnt=0;
int boardArea=0; //미친 초기화가 문제였다. 이딴 실수 제발 하지 말자
vector <int> vec;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cin>>m>>n>>k; 

    queue<pair<int,int>> que;

    for(int i=0;i<k;i++){
        int x1,y1,x2,y2;
        cin>>x1>>y1>>x2>>y2;
        for(int j=x1;j<x2;j++){
            for(int k=y1;k<y2;k++){
                board[j][k] = 1; //
            }
        }
    }


    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++) {
            if(board[i][j]==0 && visit[i][j] ==0 ){
                cnt++;
                visit[i][j] = 1;
                que.push({i,j});
                while(!que.empty()) {
                    boardArea++;
                    pair<int,int > cur = que.front(); que.pop();
                    for(int dir=0;dir<4;dir++){
                        int curX = cur.first + dirX[dir];
                        int curY = cur.second + dirY[dir];
                        if(curX<0 || curX >=n || curY<0 || curY >=m) continue;
                        if(board[curX][curY]== 1 || visit[curX][curY] == 1 ) continue;
                        que.push({curX,curY});
                        visit[curX][curY] = 1;
                    }
                }
            }
            if(boardArea!=0) { //꼭 이렇게만 해야하나 다시 풀어봐야지
                vec.push_back(boardArea);
                boardArea = 0;
            }
        }
    }
    cout<<cnt<<"\n";
    sort(vec.begin(),vec.end());
    for(int i=0;i<vec.size();i++){
        cout<<vec[i]<<" ";
    }

    // for(int i=0;i<n;i++){
    //     for(int j=0;j<m;j++){
    //         cout<<visit[i][j]<<" ";
    //     }
    //     cout<<"\n";
    // }
    return 0;
}