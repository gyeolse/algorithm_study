#include <iostream>
#include <queue>
#include <vector>
#include <algorithm>
#include <string>
#include  <stack>
#define MAX 11

using namespace std;
int n, m;
int arr[MAX][MAX];
int visit[MAX][MAX];
int dirX[4] = { -1,0,1,0 };
int dirY[4] = { 0,1,0,-1 };
queue<pair<int, int>> que;

vector < pair<int, pair<int, int>>>vec;

int parent[11] = { 0 };
int sumCnt = 0;
int ans = 0;
int mergeCnt = 0;

// for Union Find
int find(int n) {
    if (parent[n] == n) return n;
    else
        return parent[n] = find(parent[n]);
}

bool ismerge = false;

void unionParent(int x, int y) {
    x = find(x);
    y = find(y);
    ismerge = false;

    if (x == y) return;

    parent[x] = y;
    ismerge = true;
}


int main() {
    cin >> n >> m;

    // input
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cin >> arr[i][j];
        }
    }

    // 1. 서로 다른 곳 마킹 진행
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (arr[i][j] == 1 && visit[i][j] == 0) {
                sumCnt++;
                que.push({ i,j });
                visit[i][j] = sumCnt;

                while (!que.empty()) {
                    // pop
                    pair<int, int> cur = que.front(); que.pop();

                    // 4 directions
                    for (int dir = 0; dir < 4; dir++) {
                        int curX = dirX[dir] + cur.first;
                        int curY = dirY[dir] + cur.second;

                        if (curX >= 0 && curX < n && curY >= 0 && curY < m) {
                            // no visit
                            if (arr[curX][curY] != 0 && visit[curX][curY] == 0) {
                                visit[curX][curY] = sumCnt;
                                que.push({ curX,curY });
                            }
                        }
                    }
                }
            }
        }
    }

    // 2. 다리 만들기 
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (visit[i][j] != 0) {

                for (int dir = 0; dir < 4; dir++) {
                    int nowX = i;
                    int nowY = j;
                    int nowSum = visit[i][j];
                    int cnt = 0;
                    int dx, dy; // nx ny 
                    int gosum = -1; // 가고자 하는 곳

                    while (1) {
                        dx = nowX + dirX[dir];
                        dy = nowY + dirY[dir];

                        if (!(dx >= 0 && dx < n && dy >= 0 && dy < m)) break;
                        if (visit[dx][dy] = nowSum) break;
                        if (visit[dx][dy] != nowSum && visit[dx][dy] != 0) {
                            gosum = visit[dx][dy];
                            break;
                        }
                        nowX = dx;
                        nowY = dy;
                        cnt++;
                    }
                    // vector 에 넣기
                    if (gosum != -1 && cnt >= 2) {
                        vec.push_back({ cnt, {nowSum, gosum} });
                    }
                }
            }
        }
    }

    // 3. union - find 
    sort(vec.begin(), vec.end());

    for (int i = 0; i < 11; i++) {
        parent[i] = i;
    }

    for (int i = 0; i < vec.size(); i++) {
        unionParent(vec[i].second.first, vec[i].second.second);

        if (ismerge) {
            ans += vec[i].first;
            mergeCnt++;
        }
    }

    cout << mergeCnt << " " << sumCnt << endl;

    if (mergeCnt + 1 == sumCnt) {
        cout << ans << "\n";
    }
    else {
        cout << "-1" << "\n";
    }


    return 0;
}