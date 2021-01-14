#include <bits/stdc++.h>
using namespace std;

int n, m, x, y, k;
int board[20][20]; //input
int dirX[4] = { 0,0,-1,1 }; //동 서 북 남
int dirY[4] = { 1,-1,0,0 };

bool isAvailable(int x, int y) {
    if (x < 0 || y < 0 || x >= n || y >= m) return false;
    return true;
}

vector<int> changeDice(int curCmd, vector<int> dice) {
    //벡터 복사
    vector<int> tempDice = { 0,0,0,0,0,0 };
    //curCmd에 따른 주사위 변환 실행
    if (curCmd == 2) {
        tempDice[2] = dice[5];
        tempDice[4] = dice[0];
        tempDice[5] = dice[4];
        tempDice[0] = dice[2];

        tempDice[1] = dice[1];
        tempDice[3] = dice[3];
    }
    else if (curCmd == 1) {
        tempDice[5] = dice[2];
        tempDice[0] = dice[4];
        tempDice[4] = dice[5];
        tempDice[2] = dice[0];

        tempDice[1] = dice[1];
        tempDice[3] = dice[3];
    }
    else if (curCmd == 3) {
        tempDice[1] = dice[5];
        tempDice[0] = dice[1];
        tempDice[5] = dice[3];
        tempDice[3] = dice[0];

        tempDice[2] = dice[2];
        tempDice[4] = dice[4];
    }
    else if (curCmd == 4) {
        tempDice[5] = dice[1];
        tempDice[1] = dice[0];
        tempDice[3] = dice[5];
        tempDice[0] = dice[3];

        tempDice[2] = dice[2];
        tempDice[4] = dice[4];
    }

    return tempDice;
}

int main() {
    cin.tie(NULL); ios::sync_with_stdio(false);
    cin >> n >> m >> x >> y >> k;
    for (int i = 0;i < n;i++) {
        for (int j = 0;j < m;j++) {
            cin >> board[i][j];
        }
    }

    pair<int, int> dice_direction;ㅇ //다이스의 좌표를 저장하는 변수
        dice_direction = { x,y };

    int curCmd = 0;

    vector<int> dice = { 0,0,0,0,0,0 };

    int idx = 0;

    while (1) {
        idx++;
        if (idx == (k + 1)) break;
        curCmd = 0;
        cin >> curCmd;
        int curX = dice_direction.first + dirX[curCmd - 1];
        int curY = dice_direction.second + dirY[curCmd - 1];
        //1. 주사위가 밖으로 나가는 좌표인지 확인 -> 밖에 나가면 무시 (continue)
        if (!isAvailable(curX, curY)) {
            continue;
        }

        //2. 주사위 변환 처리 
        dice_direction = { curX,curY }; //주사위 좌표 새로고침
        dice = changeDice(curCmd, dice); //dice와 curCmd를 넘겨줌.
        // cout<<"current dice status : ";
        // for(int i=0;i<6;i++){
        //     cout<<dice[i]<<" ";
        // }
        // cout<<endl;
        //3. 주사위 이동 후, 이동한 칸에 쓰인 수를 확인 -> 0? 0아님?
        if (board[curX][curY] == 0) {
            board[curX][curY] = dice[5];
        }
        else {
            dice[5] = board[curX][curY];
            board[curX][curY] = 0;
        }
        // cout<<"change dice status : ";
        // for(int i=0;i<6;i++){
        //     cout<<dice[i]<<" ";
        // }
        // cout<<endl;
        cout << dice[0] << "\n";
    }
    return 0;
}