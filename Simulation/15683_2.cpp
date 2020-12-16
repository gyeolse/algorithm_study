#include <bits/stdc++.h>
using namespace std;
int n, m; //4 6, 
int board1[10][10]; //input으로 받은 값
int board2[10][10]; //사각지대 측정 위해서
int dirX[4] = { 1,0,-1,0 };
int dirY[4] = { 0,1,0,-1 };

bool isAvailable(int x, int y) {
    if (x < 0 || y < 0 || x >= n || y >= m) return false;
    return true;
}

void upd(int x, int y, int dir) { //# 처리
    dir %= 4; // ? 왜 또해주나 ?? 시간초과가 남
    while (1) {
        x += dirX[dir];
        y += dirY[dir];
        if (!isAvailable(x, y) || board2[x][y] == 6) return; //벽이거나, 범위 밖일 떄
        if (board2[x][y] != 0) continue;
        board2[x][y] = 7; //cctv가 감시할 수 있는 부분
    }
}
vector<pair<int, int>> cctv; //cctv가 위치한 좌표값
int main() {
    ios::sync_with_stdio(false);
    int square_area = 0;
    cin >> n >> m; //4,6    

    //1. input 
    for (int i = 0;i < n;i++) {
        for (int j = 0;j < m;j++) {
            cin >> board1[i][j];
            if (board1[i][j] != 6 && board1[i][j] != 0) cctv.push_back({ i,j });
            if (board1[i][j] == 0) square_area++; //최솟값을 세팅
        }
    }

    //2. 경우의 수 => next_permutation이나 진법을 이용. 여기서는 진법을 사용함.
    //cctv의 갯수만큼의 진법. shift 연산을 사용해서 loop 수행
    for (int numOfCase = 0; numOfCase < (1 << (2 * cctv.size()));numOfCase++) {
        for (int i = 0;i < n;i++)
            for (int j = 0;j < m;j++) {
                board2[i][j] = board1[i][j];
            }


        // numOfCase를 진법으로 나누면, 각 cctv가 바라보는 위치가 세팅된다.
        int curCase = numOfCase;
        for (int i = 0;i < cctv.size();i++) {
            int dir = curCase % 4; //위치를 정해줌
            curCase /= 4; //다음 case에서 쓰기 위해 /4
            int x = cctv[i].first;
            int y = cctv[i].second;
            if (board1[x][y] == 1) {
                upd(x, y, dir); //1방향만
            }
            else if (board1[x][y] == 2) {
                upd(x, y, dir);
                upd(x, y, dir + 2); //수평, 수직방향
            }
            else if (board1[x][y] == 3) {
                upd(x, y, dir);
                upd(x, y, dir + 1); // 90도 방향
            }
            else if (board1[x][y] == 4) {
                upd(x, y, dir);
                upd(x, y, dir + 1);
                upd(x, y, dir + 2); //3방향
            }
            else if (board1[x][y] == 5) {
                upd(x, y, dir);
                upd(x, y, dir + 1);
                upd(x, y, dir + 2);
                upd(x, y, dir + 3);
            }
        }

        int tmp = 0;
        for (int i = 0;i < n;i++) {
            for (int j = 0;j < m;j++) {
                if (board2[i][j] == 0) {
                    tmp++;
                }
            }
        }
        square_area = min(square_area, tmp);
    }
    cout << square_area;
    return 0;
}