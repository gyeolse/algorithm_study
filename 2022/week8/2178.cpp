/***
 * 미로탐색 : https://www.acmicpc.net/problem/2178
 * 문제 : (N, M)의 위치로 이동할 때 지나야 하는 최소의 칸 수를 구하기
 * 풀이 : bfs 순회 하면서, chk 에 해당 좌표에 도달할 수 있는 최소의 칸을 업데이트
 *
 * n, m : (2 <= n, m <= 100)
*/

#include <bits/stdc++.h>
using namespace std;
int n, m;
string s;
int board[110][110];
int chk[110][110];

int dirX[4] = { 1,0,-1,0 };
int dirY[4] = { 0,1,0,-1 };

int main() {
    cin.tie(NULL); ios::sync_with_stdio(false);
    cin >> n >> m;
    for (int i = 0;i < n;i++) {
        cin >> s;
        for (int j = 0;j < m;j++) {
            if (s[j] == '1') board[i][j] = 1;
        }
    }
    //항상 0,0에서 시작.
    queue<pair<int, int>> que;
    que.push({ 0,0 });
    chk[0][0] = 1;

    while (!que.empty()) {
        pair<int, int> cur = que.front(); que.pop();
        for (int dir = 0;dir < 4;dir++) {
            int curX = cur.first + dirX[dir];
            int curY = cur.second + dirY[dir];
            //방문 체크. 갈 수 있는지 체크
            if (chk[curX][curY] != 0 || board[curX][curY] == 0) continue;
            //보드 밖 아닌지 체크
            if (curX < 0 || curY < 0 || curX >= n || curY >= m) continue;
            // push하고, 방문 처리
            que.push({ curX,curY });
            // chk = 전의 +1
            chk[curX][curY] = chk[cur.first][cur.second] + 1;
        }
    }
    cout << chk[n - 1][m - 1] << "\n";
    return 0;
}