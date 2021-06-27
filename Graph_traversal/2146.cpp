//https://www.acmicpc.net/problem/2146
#include <bits/stdc++.h>
using namespace std;

int arr[101][101]; //입력값
int board[101][101]; //섬 cnt
int visit[101][101];
int n;
int dirX[4] = {1,0,-1,0};
int dirY[4] = {0,1,0,-1};

int main() {
    cin>>n;
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            cin>>arr[i][j];
        }
    }
    //step1. bfs를 통해서, 섬에 수를 지정해주기
    int cnt;
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            if(arr[i][j]!=1 || board[i][j]!=0) continue;
            cnt++;
            board[i][j] = cnt;
            visit[i][j] = 1; 
            queue<pair<int,int>> que;
            que.push({i,j});
            while(!que.empty()){
                pair<int,int> cur = que.front(); que.pop();
                for(int dir=0;dir<4;dir++){
                    int curX = dirX[dir] + cur.first;
                    int curY = dirY[dir] + cur.second;
                    //범위 체크 
                    if(curX<0||curY<0||curX>=n|curY>=n) continue;
                    //수 체크 
                    if(arr[curX][curY]!=1 || board[curX][curY]>0 || visit[curX][curY]!=0) continue;
                    //변수 설정
                    board[curX][curY] = cnt;
                    visit[curX][curY] = 1;                    
                    //push                 
                    que.push({curX,curY});    
                }
            }
        }
    }

    /** https://mygumi.tistory.com/109 참고함.
     * 간척사업 : 각 섬의 주변을 한 칸씩 확장하는 과정을 말함.
     * step2. 간척사업을 위해 각 섬을 큐에 넣음.
     * step3. 간척사업중 서로 다른 섬이 만난다면 그 때의 경로를 측정
     * 측정된 경로중 가장 짦은 경로를 조사함.
    */
   
// //    // step2. 바다를 접하는 점들을 모두 vector에 넣기
//     vector<pair<int,int>> vec;
//     for(int i=0;i<n;i++){
//         for(int j=0;j<n;j++){
//             if(board[i][j]==0) continue;
//             for(int dir=0;dir<4;dir++){
//                 int curX = dirX[dir] + i;
//                 int curY = dirY[dir] + j;
//                 if(curX >=n || curY>=n || curX <0 || curY <0) continue;
//                 if(board[i][j]!=0 && board[curX][curY] ==0 ) {
//                     vec.push_back({i,j});
//                     break;
//                 }
//             }
//         }
//     }

    return 0;
}
