#include <bits/stdc++.h>
using namespace std;
#define MAX 501
int h, w;
int board[501];
int res = 0;

int main() {
    cin >> h >> w; //세로길이 h, 가로길이 w

    for(int i=0;i<w;i++) {
        cin>>board[i];
    }

    //i번째 -> 가로길이 board[i]
    for(int i=1;i<w-1;i++) {
        //0. 맨 처음과 맨 마지막은 예외처리

        //1. 현재 idx로부터, 양 끝에 모두 벽이 있는지 체크
        int leftWall = 0; int rightWall = 0;

        //2. 벽이 존재하는 경우

        for(int j = 0; j<i;j++) {
            if(board[j] > board[i] ) {
                leftWall = max(leftWall, board[j]);
            }
        }

        for(int j = i + 1; j <= w-1;j++ ) {
            if(board[j] > board[i]) {
                rightWall = max(rightWall, board[j]);
            }
        }

        int minWall = min(leftWall, rightWall);

        res += max(0, minWall - board[i]);
    }

    cout<<res<<"\n";
    return 0;
}