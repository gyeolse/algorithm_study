#include <bits/stdc++.h>
using namespace std;
#define MAX 19

int board[MAX][MAX];
int dirX[4] = { 0,1,1,1 };
int dirY[4] = { 1,-1,0,1 };
//최종 결과 
bool isWin = true;
pair<int,int> res;
int winColor;
//#1. 범위 벗어나는지 검사 
bool isAvailable(int x, int y) {
    if (x > MAX || y > MAX || x < 0 || y < 0) return false;
    return true;
}

//#5. 결과가 나오지 않을 경우 -> false
//           결과가 나올 경우 -> true
bool confirmFive (int x, int y, int dir, int color) {    
    vector<pair<int,int>> v;
    //같은 컬러가
    while(board[x+dirX[dir]][y+dirY[dir]] == color ) {
        v.push_back({x+dirX[dir], y+dirY[dir]});        
    }

    if(v.size() == 5) { 
        sort(v.begin(),v.end());
        res.first = v[0].first;
        res.second = v[0].second; 
        winColor = color;
        return true;
    }
    else {
        return false;
    }   
}

int main(void) {
    //1. input
    for (int i = 0;i < 19;i++) {
        for (int j = 0;j < 19;j++) {
            cin >> board[i][j];
        }
    }

    //2. 돌이 있는지 확인
    for (int i = 0;i < 19;i++) {
        for (int j = 0;j < 19;j++) {
            if (board[i][j] == 0) continue;

            int color = board[i][j];

            //3. 각 방향으로 돌을 확인하는 과정
            for (int dir = 0;dir < 4;dir++) {
                int curX = dirX[dir] + i;
                int curY = dirY[dir] + j;
                if(isAvailable(curX,curY) == false) continue; //4. 범위 벗어난 경우
                if(board[curX][curY] != color) continue; //4. 색깔이 다른 경우

                //5. 한쪽 방면으로 계속 들어가서, 오목이 되는지 확인하는 과정
                //현재 방향, 현재 dir이랑, i,j랑 color를 넘겨줌
                isWin = confirmFive(i,j,dir, color);
            }
        }
    }

    //3. 결과 출력
    if(isWin == true) {
        cout<<res.first<<" "<<res.second<<"\n";
    } else {
        cout<<"-1"<<"\n";
    }
}