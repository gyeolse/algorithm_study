#include <bits/stdc++.h>
using namespace std;

int board[10][10];
int n, m;
vector<pair<int, int>> zero_position; //0의 위치
int tempBoard[10][10]; //초기화용
int chk[10][10]; //방문 체크용

int dirX[4] = { 0,1,0,-1 };
int dirY[4] = { 1,0,-1,0 };
int maxArea = 0;

int main() {
    //input && zero의 위치를 넣어줌
    cin >> n >> m;
    for (int i = 0;i < n;i++) {
        for (int j = 0;j < m;j++) {
            cin >> board[i][j];
            if (board[i][j] == 0) {
                zero_position.push_back({ i,j });
            }
            tempBoard[i][j] = board[i][j]; //loop에서 쓸 용도
        }
    }
    //1. zero의 크기만큼 0,1로 이루어진 벡터를 만들고, 경우의 수를 돌려야함.
    vector <int> zero_selection;
    for (int i = 0;i < zero_position.size() - 3;i++) {
        zero_selection.push_back(0);
    }
    for (int i = 0;i < 3;i++) {
        zero_selection.push_back(1);
    }

    //전체 0중 1로 바꿀 3개의 idx를 고르고, 해당 idx만 따와서 원래 board에 세팅
    do
    {
        //1 세팅
        vector<pair<int, int>> newWall;
        for (int i = 0;i < zero_selection.size();i++) { //0의 갯수만큼 돌음
            if (zero_selection[i] == 1) {
                pair<int, int> curWall = zero_position[i];
                tempBoard[curWall.first][curWall.second] = 1;
                newWall.push_back(curWall);
            }
        }

        //tempBoard는 제대로 세팅되고 있음.

        // bfs
        queue<pair<int, int>> que;
        memset(chk,0,sizeof(chk));

        for (int i = 0;i < n;i++) {
            for (int j = 0;j < m;j++) {
                if (tempBoard[i][j] == 2) {
                    que.push({ i,j });
                    chk[i][j] = 1;
                }
            }
        }

        while (!que.empty()) {
            pair<int, int> cur = que.front(); que.pop();
            int x = cur.first; int y = cur.second;
            for (int dir = 0;dir < 4;dir++) {
                int curX = x + dirX[dir];
                int curY = y + dirY[dir];
                if (curX < 0 || curY < 0 || curX >= n || curY >= m) continue;
                if (tempBoard[curX][curY] == 1 || chk[curX][curY] == 1) continue;
                chk[curX][curY] = 1;
                tempBoard[curX][curY] = 2;
                que.push({ curX,curY });
            }
        }

        // for(int i=0;i<n;i++){
        //     for(int j=0;j<m;j++){
        //         cout<<tempBoard[i][j]<<" ";
        //     }
        //     cout<<endl;
        // }
        //     cout<<endl;
        
        //안전영역 세기
        int temp = 0;
        for (int i = 0;i < n;i++) {
            for (int j = 0;j < m;j++) {
                if (tempBoard[i][j] == 0) {
                    temp++;
                }
                tempBoard[i][j] = board[i][j];
            }
        }
        maxArea = max(temp, maxArea);

    } while (next_permutation(zero_selection.begin(), zero_selection.end()));


    cout << maxArea << endl;


    return 0;
}