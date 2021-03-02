#include <bits/stdc++.h>
using namespace std;

int board[1001][1001];
int n, m;
int dirX[8] = {};
int dirY[8] = {};
int main() {
    queue<pair<int, int>> que;

    cin >> n >> m;
    for (int i = 0;i < n;i++) {
        string s;
        cin >> s;
        for (int j = 0;j < s.size();j++) {
            if (s[j] == '.') {
                board[i][j] = 0;
            }
            else {
                board[i][j] = s[j] - '0';
                que.push({ i,j });
            }
        }
    }


    //while문을 한번 더 감싸주어야함. 
    while (!que.empty()) {
        auto cur = que.front(); que.pop();

        //1. 8방향 체크 및 내 위치 visit 처리 할 필요 있나...? 

        //2. 전 board와 현재의 board를 비교함. 같다면 while문 탈출
        // 다르다면, swap 진행


    }
    // for (int i = 0;i < n;i++) {
    //     for (int j = 0;j < m;j++) {
    //         cout << board[i][j] << " ";
    //     }
    //     cout << endl;
    // }

    return 0;
}