#include <iostream>
#include <algorithm>
#include <queue>

using namespace std;

struct Fish {
    int x; int y; int dir; bool live;
};

int ans;
int MAP[4][4];
Fish fs[20];

int dirX[9] = { 0, -1, -1, 0, 1, 1, 1, 0, -1 };
int dirY[9] = { 0, 0, -1, -1, -1, 0, 1, 1, 1 };

int Max(int a, int b) { if (a > b) return a; else return b; }

void dfs(int x, int y, int dir, int sum) {
    ans = Max(ans, sum);
    int copy_map[4][4];
    Fish copy_fish[20];
    copy_state(copy_map, MAP, copy_fish, fs);
    move_fish();

    for (int i = 1;i <= 3;i++) {
        int nx = x + dirX[dir] * i;
        int ny = y + dirY[dir] * i;

        if (nx >= 0 && ny >= 0 && nx < 4 && ny < 4) {
            int fish_num = MAP[nx][ny];
            int nDir = fs[fish_num].dir;

            make_state(x, y, nx, ny, fish_num, true);
            dfs(nx, ny, nDir, sum + fish_num);
            make_state(x, y, nx, ny, fish_num, false);
        }
        else break;
    }
    copy_state(MAP, copy_map, fs, copy_fish);
}


int main() {


    return 0;
}