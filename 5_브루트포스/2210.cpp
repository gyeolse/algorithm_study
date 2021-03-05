#include <bits/stdc++.h>
using namespace std;

int board[5][5];
int dirX[4] = { 1,0,-1,0 };
int dirY[4] = { 0,1,0,-1 };

set<string> s;

int main() {
    for (int i = 0;i < 5;i++) {
        for (int j = 0;j < 5;j++) {
            cin >> board[i][j];
        }
    }

    for (int i = 0;i < 5;i++) {
        for (int j = 0;j < 5;j++) {
            queue<pair<int, pair<int, string>>> que;
            que.push({ i,{j,to_string(board[i][j])} });
            while (!que.empty()) {
                auto cur = que.front(); que.pop();
                int curX = cur.first;
                int curY = cur.second.first;
                string curString = cur.second.second;

                if (curString.size() == 6) {
                    s.insert(curString);
                    continue;
                }

                for (int dir = 0;dir < 4;dir++) {
                    int dx = dirX[dir] + curX;
                    int dy = dirY[dir] + curY;
                    if (dx < 0 || dy < 0 || dx >= 5 || dy >= 5) continue;
                    que.push({ dx,{dy,curString + to_string(board[dx][dy])} });
                }
            }
        }
    }

    cout << s.size() << "\n";
    return 0;
}