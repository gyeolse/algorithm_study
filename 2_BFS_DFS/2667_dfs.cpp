//단지번호 붙이기
#include <bits/stdc++.h>
using namespace std;

int board[30][30];
int chk[30][30];
int n = 0;
string s;
//direction
int dirX[4] = { 1,0,-1,0 };
int dirY[4] = { 0,1,0,-1 };

void output() {
    for (int i = 0;i < n;i++) {
        for (int j = 0;j < n;j++) {
            cout << chk[i][j] << " ";
        }
        cout << endl;
    }
}

void input() {
    cin >> n;
    for (int i = 0;i < n;i++) {
        cin >> s;
        for (int j = 0;j < n;j++) {
            if (s[j] == '1') board[i][j] = 1;
        }
    }
}

bool isAvailable(int x, int y) {
    if (x < 0 || y < 0 || x >= n || y >= n) return false;
    return true;
}

void dfs(int i, int j, int cnt) {

    chk[i][j] = cnt;

    for (int dir = 0;dir < 4;dir++) {
        int curX = dirX[dir] + i;
        int curY = dirY[dir] + j;

        if (!isAvailable(curX, curY)) continue;
        if (board[curX][curY] != 1 || chk[curX][curY] != 0) continue;
        dfs(curX, curY, cnt);
    }
    //사방팔방 탐색 
    // visit[i][j] = cnt;

    // dfs(i + 1, j, cnt);
    // dfs(i, j + 1, cnt);
    // dfs(i - 1, j, cnt);
    // dfs(i, j - 1, cnt);
}
void solution() {
    //dfs로 해결하기 
    memset(chk, 0, sizeof(chk));
    vector<int> vec;

    int cnt = 0;
    for (int i = 0;i < n;i++) {
        for (int j = 0;j < n;j++) {
            if (board[i][j] == 1 && chk[i][j] == 0) {
                cnt++;
                dfs(i, j, cnt);
                vec.push_back(cnt);
            }
        }
    }

    vector<int> res;
    for (int i = 0;i < vec.size();i++) {
        int cur = vec[i];
        int curCnt = 0;

        for (int j = 0;j < n;j++) {
            for (int k = 0;k < n;k++) {
                if (chk[j][k] == cur) {
                    curCnt++;
                }
            }
        }
        res.push_back(curCnt);
    }

    sort(res.begin(), res.end());

    cout << res.size() << "\n";
    for (int i = 0;i < res.size();i++) {
        cout << res[i] << "\n";
    }
}

int main() {

    input();

    solution();

    // output();
    return 0;
}