#include <bits/stdc++.h>
#define MAX 101
using namespace std;

int n, m, k;
int A[MAX][MAX];
int board[MAX][MAX];

int x, y, z;
// vector<pair<int, pair<int, int>>> treeVec; //나이, x,y
vector<int> treeVec[MAX][MAX]; //나이에 대해서 vector에 저장

int dirX[8] = { -1,-1,-1,0,0,1,1,1 };
int dirY[8] = { -1,0,1,-1,1,-1,0,1 };

void spring() {
    // 
    for (int i = 1;i <= n;i++) {
        for (int j = 1;j <= n;j++) {
            if (treeVec[i][j].size() == 0) continue;

            int dieTree = 0;
            vector<int> temp;

            //정렬 꼭 해주어야함 -> 나이 어린 나무부터 
            sort(treeVec[i][j].begin(), treeVec[i][j].end());
            for (int k = 0;k < treeVec[i][j].size();k++) {
                // 각 나무를 cnt;
                int curTree = treeVec[i][j][k];

                if (board[i][j] >= curTree) {
                    board[i][j] -= curTree;
                    temp.push_back(curTree + 1);
                }
                else {
                    dieTree += curTree / 2;
                }
            }

            treeVec[i][j].clear();

            for (int k = 0;k < temp.size();k++) {
                treeVec[i][j].push_back(temp[k]);
            }

            board[i][j] += dieTree;
        }
    }

}

void fall() {
    // 퍼뜨리기 
    for (int i = 1;i <= n;i++) {
        for (int j = 1;j <= n;j++) {
            if (treeVec[i][j].size() == 0) continue;

            for (int k = 0;k < treeVec[i][j].size();k++) {
                if (treeVec[i][j][k] % 5 == 0) {
                    for (int dir = 0;dir < 8;dir++) {
                        int dx = dirX[dir] + i;
                        int dy = dirY[dir] + j;

                        if (dx >= 1 && dy >= 1 && dx <= n && dy <= n) {
                            treeVec[dx][dy].push_back(1);
                        }
                    }
                }
            }
        }
    }
}

// 양분을 줌
void winter() {
    for (int i = 1;i <= n;i++) {
        for (int j = 1;j <= n;j++) {
            board[i][j] += A[i][j];
        }
    }
}

void testBoard() {
    int ans = 0;
    for (int i = 1;i <= n;i++) {
        for (int j = 1;j <= n;j++) {
            ans += treeVec[i][j].size();
        }
    }

    cout << ans << endl;
}

int main() {
    cin.tie(NULL); ios::sync_with_stdio(false);
    cin >> n >> m >> k; //크기 N, M개의 나무수, K년 후
    for (int i = 1;i <= n;i++) {
        for (int j = 1;j <= n;j++) {
            cin >> A[i][j];
            board[i][j] = 5; //초기 양분은 5....
        }
    }

    for (int i = 1;i <= m;i++) {
        cin >> x >> y >> z;
        treeVec[x][y].push_back(z);
    }

    for (int i = 0;i < k;i++) {
        // 봄
        spring();

        // 가을
        fall();

        // 겨울
        winter();
    }
    // 보드 출력
    testBoard();
    return 0;
}