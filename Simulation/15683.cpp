#include <bits/stdc++.h>
using namespace std;

int board1[10][10];
int board2[10][10];
int dirX[4] = { 1,0,-1,0 };
int dirY[4] = { 0,1,0,-1 };
int n, m;
vector<pair<int, int>> cctv;

bool isAvailable(int x, int y) {
    if (x < 0 || y < 0 || x >= n || y >= m) return false;
    return true;
}

void upd(int x, int y, int dir) {
    dir %= 4;
    while (1) {
        x += dirX[dir];
        y += dirY[dir];
        if (!isAvailable(x, y) || board2[x][y] == 6) return; //벽이거나, 못가면 return
        if (board2[x][y] != 0) continue;
        board2[x][y] = 7; //가능
    }
}

int main() {
    cin >> n >> m;
    int mn = 0;
    for (int i = 0;i < n;i++) {
        for (int j = 0;j < m;j++) {
            cin >> board1[i][j];
            if (board1[i][j] != 0 && board1[i][j] != 6) {
                cctv.push_back({ i,j });
            }
            if (board1[i][j] == 0) mn++;
        }
    }
    //                          (1<<(2*cctv.size()))
    for (int cur = 0;cur < (1 << (2 * cctv.size()));cur++) {
        for (int i = 0;i < n;i++)
            for (int j = 0;j < m;j++)
                board2[i][j] = board1[i][j];

        int brute = cur;
        for (int i = 0;i < cctv.size();i++) {
            int dir = brute % 4;
            brute /= 4;
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
        int val = 0;
        for (int i = 0;i < n;i++)
            for (int j = 0;j < m;j++)
                if (board2[i][j] == 0) {
                    val++;
                }


        mn = min(mn, val);
    }
    cout << mn;
}