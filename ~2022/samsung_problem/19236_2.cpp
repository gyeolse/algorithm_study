#include <iostream>
#include <vector>
using namespace std;

struct Fish {
    int num; int dir;
};

Fish arr[4][4]; // map 에다가 물고기의 idx를 저장 

// direction
int dirX[8] = { -1,-1,0,1,1,1,0,-1 };
int dirY[8] = { 0,-1,-1,-1,0,1,1,1 };

int tempMax = 0;

void moveFish() {
    bool gonext = false;

    for (int i = 1;i <= 16;i++) {
        gonext = false;
        for (int j = 0;j < 4;j++) {
            for (int k = 0;k < 4;k++) {
                if (arr[j][k].num == i) { // 번호잖아
                    for (int l = 0;l < 8;l++) {
                        // 현재 방향 설정
                        int curDir = (arr[j][k].dir + l) % 8; // 현재방향푸터 ~ 쭉 돌리기
                        int curX = j + dirX[curDir];
                        int curY = k + dirY[curDir];

                        if (curX >= 0 && curX < 4 && curY >= 0 && curY < 4) {
                            if (arr[curX][curY].num != 0) {
                                //  switch
                                arr[j][k].dir = curDir; // 위치 바꿔주기
                                Fish tempFish = arr[j][k]; // 현재 위치 고기 저장
                                arr[j][k] = arr[curX][curY]; // 스위치 1
                                arr[curX][curY] = tempFish; // 스위치 2
                                gonext = true;
                                break;
                            }
                        }
                    }
                }

                if (gonext) break;
            }
            if (gonext) break;
        }
    }

}

void moveShark(int x, int y, int cnt) {

    moveFish();

    // 상어 쳐 움직이기
    Fish tempArr[4][4];

    // tempArr 만들어두기
    for (int i = 0;i < 4;i++) {
        for (int j = 0;j < 4;j++) {
            tempArr[i][j] = arr[i][j];
        }
    }

    int nowDir = arr[x][y].dir; // 현재 위치에서 방향
    int curX, curY;

    for (int k = 1;k <= 3;k++) { // 어느 방향을 가도 3번
        curX = x + (dirX[nowDir] * k);
        curY = y + (dirY[nowDir] * k);

        if (curX >= 0 && curX < 4 && curY >= 0 && curY < 4) {
            if (arr[curX][curY].num != -1) {
                arr[x][y].num = -1;
                int fisheat = arr[curX][curY].num;
                arr[curX][curY].num = 0;

                moveShark(curX, curY, cnt + fisheat);

                for (int i = 0;i < 4;i++) {
                    for (int j = 0;j < 4;j++) {
                        arr[i][j] = tempArr[i][j];
                    }
                }

            }

        }
    }

    if (cnt > tempMax) tempMax = cnt;
}

int main() {

    // input
    for (int i = 0;i < 4;i++) {
        for (int j = 0;j < 4;j++) {
            int a; int b;
            cin >> a >> b;
            Fish fs;
            fs.num = a; fs.dir = b - 1;
            arr[i][j] = fs;
        }
    }

    tempMax += arr[0][0].num;
    arr[0][0].num = 0;

    moveShark(0, 0, tempMax);

    cout << tempMax;

    return 0;
}