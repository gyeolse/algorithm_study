#include <bits/stdc++.h>
#define MAX 101
#define endl '\n'

using namespace std;
int n;  int x, y, d, g;
int dirX[4] = { 0,-1,0,1 };
int dirY[4] = { 1,0,-1,0 };

int board[MAX][MAX];

int res = 0;

vector<int> curveDirection;
void makeCurve() {
    int sz = curveDirection.size();

    for (int i = sz - 1;i >= 0;i--) {
        // 방향정보를 저장하고, 
        int curD = (curveDirection[i] + 1) % 4;
        x = x + dirX[curD];
        y = y + dirY[curD];
        board[x][y] = 1;

        curveDirection.push_back(curD);
    }
}

bool isSquare(int x, int y) {
    if (board[x][y] ==1  && board[x + 1][y + 1] ==1 && board[x][y + 1] ==1  && board[x + 1][y] ==1 ) {
        return true;
    }
    return false;
}
void countSquare() {
    for (int i = 0;i < MAX;i++) {
        for (int j = 0;j < MAX;j++) {
            if (isSquare(i, j)) {
                res++;
            }
        }
    }
}

int main() {
    cin >> n;
    for (int i = 0;i < n;i++) {
        cin >> y >> x >> d >> g;
        // 방향정보 초기화
        curveDirection.clear();

        // 현재 x,y 위치를 1로 설정
        board[x][y] = 1;
        x += dirX[d];
        y += dirY[d];

        // d만큼 이동한 위치를 1로 설정
        board[x][y] = 1;

        curveDirection.push_back(d);
        // 세대 만큼 이동
        for (int j = 0;j < g;j++) {
            makeCurve();
        }

    }

    // 정사각형 갯수 세기
    countSquare();

    cout<<res<<"\n";
    return 0;
}