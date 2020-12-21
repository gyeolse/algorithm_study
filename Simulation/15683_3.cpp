#include <bits/stdc++.h>
#include <iostream>

using namespace std;

int n, m;
int board1[10][10];
int board2[10][10];

int dirX[4] = { 1,0,-1,0 };
int dirY[4] = { 0,1,0,-1 };

vector<pair<int, int>> vec;


bool isAvailable(int x, int y) {
    if (x < 0 || y < 0 || x >= n || y >= m) return false;
    return true;
}
void upd(int x, int y, int dir) { //못갈때까지 계속 간다 
    dir%=4;
    while(1) {
        x+=dirX[dir];
        y+=dirY[dir];

        if(!isAvailable(x,y) || board2[x][y] ==6) return;
        if(board2[x][y] !=0) continue;
        board2[x][y] = 7;        
    }
}

int main(void) {
    int _min=0;
    cin >> n >> m; //4 6

    for (int i = 0;i < n;i++) {
        for (int j = 0;j < m;j++) {
            cin >> board1[i][j];
            if(board1[i][j] !=6 && board1[i][j] !=0) vec.push_back({i,j});
            if(board1[i][j] == 0) _min++;
        }
    }

    //1. cctv의 갯수만큼 shift. cur이 cctv의 갯수에 따라. cctv 경우의 수만큼 돌 것임
    for (int cur = 0;cur < (1 << (2 * vec.size()));cur++) {
        //board1 to board2 (이번 loop에서 사용할 board)
        for (int i = 0;i < n;i++) {
            for (int j = 0;j < m;j++) {
                board2[i][j] = board1[i][j];
            }
        }

        int temp = cur;
        for (int i = 0;i < vec.size();i++) {
            //3. 방향이 4개 이므로, 4로 나눠주는 걸 계속 해줌
            //4. 각 방향별로 세팅을 해줌.
            int dir = temp % 4;
            temp /= 4;
            int x = vec[i].first;
            int y = vec[i].second;
            if (board1[x][y] == 1) {
                upd(x, y, dir);
            }
            else if (board1[x][y] == 2) {
                upd(x, y, dir);
                upd(x, y, dir + 2);
            }
            else if (board1[x][y] == 3) {
                upd(x, y, dir);
                upd(x, y, dir + 1);
            }
            else if (board1[x][y] == 4) {
                upd(x, y, dir);
                upd(x, y, dir + 1);
                upd(x, y, dir + 2);
            }
            else if (board1[x][y] == 5) {
                upd(x, y, dir);
                upd(x, y, dir + 1);
                upd(x, y, dir + 2);
                upd(x, y, dir + 3);
            }
        }
        //5. min 값 비교
        int tmp = 0;
        for(int i=0;i<n;i++) { 
            for(int j=0;j<m;j++) { 
                if(board2[i][j] == 0) tmp++;
            }
        }
        _min = min(_min,tmp);
    }

    cout << _min;
    return 0;
}