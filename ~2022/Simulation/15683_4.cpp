#include <bits/stdc++.h>
using namespace std;
int n, m;
int board1[10][10];
int board2[10][10];

int dirX[4] = { 1,0,-1,0 };
int dirY[4] = { 0,1,0,-1 };

vector<pair<int, int>> cctv; //cctv가 있는 곳의 위치 저장

bool isAvailable(int x, int y) {
    //방문하지 못하는 경우 == 범위를 넘는 경우
    if (x < 0 || y < 0 || x >= n || y >= m) return false;
    return true;
}

void upd(int x, int y, int dir) {
    //방문 체킹
    dir %= 4;
    while (1) {
        x += dirX[dir];
        y += dirY[dir];

        if (!isAvailable(x,y) || board2[x][y] == 6) return; //못 간다. 막혔다.
        if (board2[x][y] != 0) continue; //갈 수는 있는데, 이미 진행함.
        board2[x][y] = 7; //cctv 감시할 수 있는 부분 설정
    }

}

int main() {
    int min_square_area = 0; // 사각지대 최소 크기
    //1. input
    cin >> n >> m;

    for (int i = 0;i < n;i++) {
        for (int j = 0;j < m;j++) {
            cin >> board1[i][j];
            if (board1[i][j] != 0 && board1[i][j] != 6) cctv.push_back({ i,j }); //벽이 아니고, 빈 칸이 아닌 경우 
            if (board1[i][j] == 0) min_square_area++; //벽이 아니고, 0인 경우
        }
    }

    //2. cctv의 위치에서 주위 탐색 시작
    //1) cctv의 갯수에 따른 경우의 수 => 순열 => 진법에 따라서 
    for (int numOfCase = 0;numOfCase < (1 << (2 * cctv.size()));numOfCase++) {
        //이번 loop에서 쓸 board2배열
        for (int i = 0;i < n;i++) {
            for (int j = 0;j < m;j++) {
                board2[i][j] = board1[i][j];
            }
        }

        //2) cctv 위치 세팅  => 각 순서에 맞게 값 변환 
        int temp = numOfCase;
        for (int i = 0;i < cctv.size();i++) {
            int dir = temp % 4;
            temp /= 4;
            int x = cctv[i].first;
            int y = cctv[i].second;

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
        //3) 최소 영역 측정
        int curArea = 0;
        for (int i = 0;i < n;i++) {
            for (int j = 0;j < m;j++) {
                if (board2[i][j] == 0) {
                    curArea++;
                }
            }
        }
        min_square_area = min(curArea, min_square_area);
    }
    cout << min_square_area;
    return 0;
}