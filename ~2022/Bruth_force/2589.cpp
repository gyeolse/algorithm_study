#include <bits/stdc++.h>
using namespace std;

//가로, 세로 크기는 각각 50 이하
int board[50][50];
int chk[50][50];
int n, m;
int dirX[4] = { 0,1,0,-1 };
int dirY[4] = { 1,0,-1,0 };

int main() {
    //1. input
    cin >> n >> m;
    for (int i = 0;i < n;i++) {
        string x; cin >> x;
        for (int j = 0;j < x.size();j++) {
            if (x[j] == 'L') {
                board[i][j] = 1;
            }
        }
    }

    int maxValue = 0;
    //2. 모두 순회
    for (int i = 0;i < n;i++) {
        for (int j = 0;j < m;j++) {
            if (board[i][j] == 1) {
                queue<pair<int, int>> que;
                memset(chk, 0, sizeof(chk));
                que.push({ i,j });
                chk[i][j] = 1; //chk 배열에 이동 시간을 계산
                while (!que.empty()) {
                    auto cur = que.front(); que.pop();

                    for (int dir = 0;dir < 4;dir++) {
                        int curX = dirX[dir] + cur.first;
                        int curY = dirY[dir] + cur.second;

                        if (curX < 0 || curY < 0 || curX >= n || curY >= m) continue;
                        if (chk[curX][curY] != 0) continue;
                        if (board[curX][curY] == 0 ) continue;
                        que.push({ curX,curY });
                        chk[curX][curY] = chk[cur.first][cur.second] + 1;
                    }
                }

                //chk에서 max 값을 찾기 
                for(int i=0;i<n;i++) {
                    for(int j=0;j<m;j++) {
                        maxValue = max(maxValue, chk[i][j]);
                    }
                }      
            }
        }
    }

    cout<<maxValue-1<<"\n";
    return 0;
}