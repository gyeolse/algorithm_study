//2573번 빙산
#include <iostream>
#include <queue>
#include <algorithm>
#include <cstring>
using namespace std;
int n, m;
int board[303][303];
int board2[303][303];
int dist[303][303];
int dirX[4] = {1, 0, -1, 0};
int dirY[4] = {0, 1, 0, -1};
int Year = 0;

int main(void)
{
    cin >> n >> m;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            cin >> board[i][j];
        }
    }
    //    for(int i=0;i<n;i++){
    //        fill(dist[i],dist[i]+m,-1);
    //    }
    while (1) { //while loop 
        int bfs_cnt=0;
        memset(dist,0,sizeof(dist));
        memset(board2,0,sizeof(board2));
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++)
            {
                if (board[i][j] == 0 || dist[i][j] != 0) continue;
                queue<pair<int, int>> que;
                bfs_cnt++;
                que.push({i, j});
                dist[i][j] = bfs_cnt;
                while (!que.empty())
                {
                    pair<int, int> cur = que.front();    que.pop();
                    for (int i = 0; i < 4; i++) {
                        int curX = cur.first + dirX[i];
                        int curY = cur.second + dirY[i];
                        if (curX < 0 || curX >= n || curY < 0 || curY >= m)    continue;
                        if (board[curX][curY] == 0 || dist[curX][curY] != 0)    continue;
                        dist[curX][curY] = bfs_cnt;
                        que.push({curX, curY});
                    }
                }
            }
        }
        //bfs가 몇 번 이루어졌는지 -> 몇덩어리인지? 
        if (bfs_cnt>=2) { cout<<Year<<endl; break; }
        if (bfs_cnt==0) { cout<<0<<endl; break;}

        //녹여주는 과정. 새로운 배열 하나를 만들어줌. 
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                int zeroCount=0; //해당 위치에서 주위 0 count                
                if(board[i][j]!=0){
                    for(int k=0;k<4;k++){
                        int curX = i+dirX[k];
                        int curY = j+dirY[k];
                        if(curX<0||curX>=n||curY<0||curY>=m) continue;
                        if(board[curX][curY]==0) zeroCount++;
                    }
                }
                board2[i][j] = board[i][j] - zeroCount;
                if(board2[i][j]<0) board2[i][j]=0;
            }
        }

        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                board[i][j] = board2[i][j];
            }
        }

        Year++;
    }
    return 0;
}