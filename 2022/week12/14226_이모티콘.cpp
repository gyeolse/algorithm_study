#include <bits/stdc++.h>
using namespace std;
#define MAX 2000
int s;
// 화면에 a 개의 이모티콘, 클립보드에 b 개의 이모티콘
int board[MAX][MAX];

int bfs() {
    queue<pair<int, int>> que;
    board[1][0] = 0;
    que.push({ 1,0 });
    while (!que.empty()) {
        pair<int, int> cur = que.front(); que.pop();
        int display = cur.first; int clip = cur.second;

        // 클립보드에 있는 거 그대로 복사
        if (board[display][display] == 0) {
            board[display][display] = board[display][clip] + 1;
            que.push({ display, display });
        }

        if (board[display + clip][clip] == 0 && (display + clip) <= s) {
            board[display + clip][clip] = board[display][clip] + 1;
            que.push({ display + clip, clip });
        }

        if (board[display - 1][clip] == 0 && (display - 1 >= 0)) {
            board[display - 1][clip] = board[display][clip] + 1;
            que.push({ display - 1, clip });
        }
    }

    int ans = 1000;

    for (int i = 0;i <= s;i++) {
        if (board[s][i] != 0) {
            if (ans != 0 && ans > board[s][i]) {
                ans = board[s][i];
            }
        }
    }

    return ans;
}

int main() {
    cin >> s;
    int res = bfs();
    cout << res << "\n";
    return 0;
}