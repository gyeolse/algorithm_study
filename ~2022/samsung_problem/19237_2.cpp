#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>

#define MAX 25
using namespace std;

struct Shark {
    int x; int y;
    bool isLive;
    int dir;
    vector<int> priority[5];
};

struct Cell {
    vector<int> v;
    int Smell; // Time
    int Host; // 누구꺼냐
};

int n, m, k;
Shark sharkArr[400]; // shark를 갖고 있는 arr
Cell arr[MAX][MAX]; // 그리고 arr가 필요하겠지

int dirX[5] = { 0,-1,1,0,0 };
int dirY[5] = { 0,0,0,-1,1 };

bool isAvailable() {
    for (int i = 2;i <= m;i++) {
        if (sharkArr[i].isLive == true) return false;
    }
    return true;
}

void makeSmell(int T) {
    // 상어가 있는 위치 
    for (int i = 1;i <= m;i++) {
        if (sharkArr[i].isLive == false) continue;

        int x_ = sharkArr[i].x;
        int y_ = sharkArr[i].y;
        arr[x_][y_].Smell = T + k;
        arr[x_][y_].Host = i;
    }
}

void moveShark(int T) {
    // 상어 움직이기

    // 1. 지금 array 에 있는 거 찾아서 일단 clear
    for (int i = 1;i <= m;i++) {
        if (sharkArr[i].isLive == false) continue;
        int x = sharkArr[i].x; int y = sharkArr[i].y;
        arr[x][y].v.clear();
    }

    // 2. 이동
    // 1. 우선순위에 맞게 움직이기 ( 아무 냄새 X )
    // 2. 우선순위에 맞게 갈 곳 없다면, 자기 냄새가 있는 곳
    // 3. 갈곳없으면 X
    for (int i = 1;i <= m;i++) {
        if (sharkArr[i].isLive == false) continue;
        int x = sharkArr[i].x; int y = sharkArr[i].y;
        int dir = sharkArr[i].dir;

        int self_x, self_y, self_dir;
        self_x = self_y = self_dir = -1;
        bool flag = false;

        for (int j = 0;j < sharkArr[i].priority[dir].size(); j++) {
            int nDir = sharkArr[i].priority[dir][j];
            int curX = dirX[nDir] + x;
            int curY = dirY[nDir] + y;

            // 갈 수 있다. 
            if (curX >= 0 && curX < n && curY >= 0 && curY < n) {
                if (arr[curX][curY].Smell <= T) {
                    flag = true;
                    arr[curX][curY].v.push_back(i);
                    sharkArr[i].x = curX;
                    sharkArr[i].y = curY;
                    sharkArr[i].dir = nDir;
                    break;
                }
                else {
                    if (arr[curX][curY].Host == i) { // 나 자신이라면
                        if (self_x == -1) {
                            self_x = curX;
                            self_y = curY;
                            self_dir = nDir;
                        }
                    }
                }
            }
        }

        if (flag == false) {
            arr[self_x][self_y].v.push_back(i);
            sharkArr[i].x = self_x;
            sharkArr[i].dir = self_dir;
            sharkArr[i].y = self_y;
        }
    }
}

void killShark() {
    // 제일 작은 상어만 남기기 
    for (int i = 1;i <= m;i++) {
        if (sharkArr[i].isLive == false) continue;

        int x_ = sharkArr[i].x; int y_ = sharkArr[i].y;
        int curSize = arr[x_][y_].v.size();
        if (curSize >= 2) {
            // 제일 작은 놈만 남기고 나머지 clear
            sort(arr[x_][y_].v.begin(), arr[x_][y_].v.end());
            int a = arr[x_][y_].v[0];

            // 남은 놈들 죽이기
            for (int j = 1;j < arr[x_][y_].v.size();j++) {
                int x = arr[x_][y_].v[j];
                sharkArr[x].isLive = false;
            }

            // vector clear 후, 작은 놈만 넣기
            arr[x_][y_].v.clear();
            arr[x_][y_].v.push_back(a);
            arr[x_][y_].Host = a;
        }
    }
}

int main() {

    // 1. input 초기화. 상어 넣어주기
    cin >> n >> m >> k;
    for (int i = 0;i < n;i++) {
        for (int j = 0;j < n;j++) {
            int a; cin >> a;
            if (a != 0) {
                arr[i][j].v.push_back(a);
                Shark s; s.x = i; s.y = j;
                sharkArr[a] = s;
            }
            arr[i][j].Host = 0;
            arr[i][j].Smell = 0;
        }
    }

    // 상어 방향
    for (int i = 1;i <= m;i++) {
        int dir; cin >> dir;
        sharkArr[i].dir = dir;
        sharkArr[i].isLive = true;
    }

    // 우선순위 (check)
    for (int i = 1;i <= m;i++) {
        for (int j = 1;j <= 4;j++) {
            int arr[4];
            cin >> arr[0] >> arr[1] >> arr[2] >> arr[3];

            for (int k = 0;k < 4;k++) {
                sharkArr[i].priority[j].push_back(arr[k]);
            }
        }
    }

    // 1000초 넘으면 -1
    for (int i = 0;i < 1001;i++) {
        if (isAvailable() == true) { // 상어 1만 남았을 때
            cout << i << "\n";
            return 0;
        }

        makeSmell(i);
        moveShark(i);
        killShark();
    }

    cout << -1 << "\n";
    return 0;
}