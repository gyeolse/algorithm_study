#include <bits/stdc++.h>
using namespace std;
int n,m;
string s;
int board[110][110];
int check[110][100];

int dirX[4] = {1,0,-1,0};
int dirY[4] = {0,1,0,-1};

int main() {
    cin.tie(NULL); ios::sync_with_stdio(false);
    cin>>n>>m;
    for(int i=0;i<n;i++){
        cin>>s;
        for(int j=0;j<m;j++){
            if(s[j]=='1') board[i][j] = 1;
        }
    }
    //항상 0,0에서 시작.
    queue<pair<int,int>> que;
    que.push({0,0});
    check[0][0]=1;

    while(!que.empty()){
        pair<int,int> cur = que.front(); que.pop();
        for(int dir=0;dir<4;dir++){
            int curX = cur.first + dirX[dir];
            int curY = cur.second + dirY[dir];
            //방문 체크. 갈 수 있는지 체크
            if(check[curX][curY]!=0 || board[curX][curY]==0) continue;
            //보드 밖 아닌지 체크
            if(curX<0||curY<0||curX>=n||curY>=m) continue;
            //push하고, 방문 처리
            que.push({curX,curY});
            //check = 전의 +1
            check[curX][curY] = check[cur.first][cur.second] + 1;
        }
    }
    cout<<check[n-1][m-1]<<"\n";
    return 0;
}