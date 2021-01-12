#include <bits/stdc++.h>
using namespace std;

int n, m;
int r, c, d;
int board[50][50]; //input board
int clean[50][50];
int dirX[4] = { 0,-1,0,1 };
int dirY[4] = { -1,0,1,0 }; //북, 동, 남, 서

int backX[4] = { 1,0,-1,0 };
int backY[4] = { 0,-1,0,1 };

bool isAvailable(int x, int y) {
    if (x >= n || y >= m || x < 0 || y < 0) return false;
    return true;
}

int main() {
    cin >> n >> m; //세로크기, 가로크기
    cin >> r >> c >> d; //로봇청소기의 처음 좌표, 방향
    for (int i = 0;i < n;i++) {
        for (int j = 0;j < m;j++) {
            cin >> board[i][j];
        }
    }
    queue <pair<int, pair<int, int>>> que;
    int curDir = d; //현재 방향
    que.push({ curDir,{r,c} });

    int cnt = 0;

    while (!que.empty()) {
        int curDir = que.front().first;
        int x = que.front().second.first;
        int y = que.front().second.second;
        que.pop();

        //1. 청소 (범위 벗어나는지, 1이 아닌지, 청소한 적이 없는지)
        if (board[x][y] == 0 && clean[x][y]==0) {
            clean[x][y] = 1;
            cnt++;
        }

        //2. 왼쪽 방향부터 탐색 진행
        for (int i = 0;i < 4; i++) {
            int left_x = x + dirX[curDir];
            int left_y = y + dirY[curDir];
            int left_dir = (curDir + 3) % 4;
            //a. 아직 청소 안한 곳이면, 글로 가고 한 칸 전진하고 1번부터 진행
            if (board[left_x][left_y] == 0 && clean[left_x][left_y] == 0) {
                que.push({ left_dir,{left_x,left_y} });
                break;
            }
            else {
                //b. 청소할 공간이 없다면, 그 곳으로 회전한 후, 2번으로 돌아가기 
                curDir = left_dir;
                //c. 네 방향 모두 청소가 되었거나 벽인 경우, 바라보는 방향 유지한 채로 한 칸 후퇴 후 2번
                if (i == 3) {
                    //바라보는 방향 유지
                    i = -1; //for loop 탈출해야함
                    //한 칸 후퇴 (x에서 후퇴, y에서 후퇴해야함. 이 떄 후퇴는 어떻게?)
                    x = x + backX[curDir];
                    y = y + backY[curDir];
                    if(board[x][y]==1) break; //갔는데 벽이면 break;
                }
                continue;
            }
        }

    }

    cout << cnt << "\n";
    return 0;
}