/**
 * 처음 시도한 풀이는 계속 시간 초과가 났다.
 *      원인 : 모든 bfs가 완료된 후에, 업데이트를 해주는 식으로 구현했는데,
 * 이렇게 하면 인덱스별로 한번 돌고, board 배열을 순회해야해서 최대 O(N^2)*N 만큼 돌게 된다.
 * 
 * 때문에, BFS를 돌면서, 그룹에 추가하고, 합과 그룹 내의 수를 카운트 해주어야한다.
 * 또한, 한 그룹이 다 끝난 후에, 바로 그룹 내의 인구 이동을 수행해주어야 맞았습니다가 뜬다.
 * 
*/

#include <bits/stdc++.h>
using namespace std;
#define MAX 51
int N, L, R; //board, L명 이상, R명 이하.
int board[MAX][MAX];
int chk[MAX][MAX];

// 우 하 좌 상
int dirX[4] = {0,1,0,-1};
int dirY[4] = {1,0,-1,0};
bool isAvailable(int a, int b) {
    if (abs(a - b) >= L && abs(a - b) <= R) return true;
    else return false;
}

int ans = 0;

int main() {
    cin.tie(NULL); ios::sync_with_stdio(false);

    //입력
    cin >> N >> L >> R;
    for (int i = 0;i < N;i++) {
        for (int j = 0;j < N;j++) {
            cin >> board[i][j];
        }
    }

    while(1) {
        queue<pair<int, int>> que;
        memset(chk, -1, sizeof(chk)); //매번 초기화
        int idx = 0;

        //1. BFS를 수행한다.
        for (int i = 0;i < N;i++) {
            for (int j = 0;j < N;j++) {
                if (chk[i][j] == -1) {
                    vector<pair<int,int>> groupNum;
                    int groupSum = board[i][j];
                    int groupCount = 1;

                    idx++;
                    que.push({ i,j });

                    chk[i][j] = idx;
                    groupNum.push_back({i,j});

                    while (!que.empty()) {
                        auto cur = que.front(); que.pop();

                        for (int dir = 0;dir < 4;dir++) {
                            int curX = cur.first + dirX[dir];
                            int curY = cur.second + dirY[dir];

                            //범위르 벗어나지 않은 경우,
                            if (curX >= N || curY >= N || curX < 0 || curY < 0) continue;
                            //chk 배열에서 -1 여부 체크
                            if (chk[curX][curY] != -1) continue;
                            //L, R 차이 여부 체크
                            if (isAvailable(board[cur.first][cur.second], board[curX][curY])) {
                                chk[curX][curY] = idx;
                                que.push({ curX,curY });

                                //그룹에 추가
                                groupNum.push_back({curX,curY});
                                groupSum += board[curX][curY];
                                groupCount += 1;
                            }
                        }
                    }

                    //여기서 분배 처리
                    for(int i=0;i<groupNum.size();i++) {
                        board[groupNum[i].first][groupNum[i].second] = groupSum/groupCount;
                    }
                }
            }
        }

        //2. while문 탈출 조건. 
        if(idx ==  (N*N)) break;

        //3. idx가 그룹이므로, 이에 따른 인구이동 해주기
        // for (int i = 1;i <= idx;i++) {
        //     //한 그룹. 
        //     int groupNum = 0;
        //     int groupTotal = 0;
        //     vector<pair<int,int>> vec;
        //     for (int j = 0;j < N;j++) {
        //         for (int k = 0;k < N;k++) {
        //             if (chk[j][k] == i) { //같은 그룹이라면
        //                 groupNum += 1; //하나를 더해주고, (사람 수)
        //                 groupTotal += board[j][k];
        //                 //현재 idx 위치를 vector에 push
        //                 vec.push_back({j,k});
        //             }
        //         }
        //     }

        //     //인구수 나누기
        //     int move_ = groupTotal / groupNum;

        //     //업데이트
        //     for(int i=0;i<vec.size();i++) {
        //         board[vec[i].first][vec[i].second] = move_;
        //     }
        // }

        ans++;
    }

    cout<<ans<<"\n";
    return 0;
}