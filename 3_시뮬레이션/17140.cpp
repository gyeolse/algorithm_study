#include <bits/stdc++.h>
using namespace std;
int r, c, k;
int board[101][101];

int main() {
    cin >> r >> c >> k; //r,c의 위치가 k가 되는지를 확인

    for (int i = 0;i < 3;i++) {
        for (int j = 0;j < 3;j++) {
            cin >> board[i][j];
        }
    }
    // 시간 100초 카운트
    int t_ = 100; 
    while(t_--) {
        
        
        // A[r][c]에 들어있는 k 값 확인
        if(board[r][c] == k) break;
    }



    // 출력
    if(board[r][c] == k ) {
        cout<<100-t_<<"\n";
    }
    else {
        cout<<-1<<"\n";
    }

    return 0;
}