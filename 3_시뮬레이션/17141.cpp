#include <bits/stdc++.h>
using namespace std;

int board[55][55];
int chk[55][55];

int n, m;

int dirX[4] = { 0,0,1,-1 };
int dirY[4] = { 1,-1,0,0 };

vector<pair<int, int>> virusLocation;

int res = 987654321;

int main() {
    //입력
    cin >> n >> m;
    for (int i = 0;i < n;i++) {
        for (int j = 0;j < n;j++) {
            cin >> board[i][j];
            if (board[i][j] == 2) {
                virusLocation.push_back({ i,j });
            }
        }
    }

    vector<int> answerVec;

    //1. 조합 생성
    vector<int> forLoop;
    int virusLocationSize = virusLocation.size();

    for (int i = 0;i < (virusLocationSize - m);i++) {  
        forLoop.push_back(0);
    }
    for(int i=0;i<m;i++) {
        forLoop.push_back(1);
    }

    //2. 조합 별로 확인
    do
    {
        int cnt = 0; 

        queue<pair<int,int>> que; 
        memset(chk,0,sizeof(chk));
        
        //3. 현재 조합에서 선택한 바이러스를 큐에 넣는다.
        for(int i=0;i<forLoop.size();i++) {
            if(forLoop[i] == 1) {
                que.push(virusLocation[i]);
                chk[virusLocation[i].first][virusLocation[i].second] = 1;
            }
        }

        int timeCnt = 0;

        //4. bfs
        while(!que.empty()) {
            //5. 큐에 있는 것을 모두 처리 
            int queSize = que.size();
            for(int i=0;i<queSize;i++) {
                auto cur = que.front(); que.pop();

                for(int dir=0;dir<4;dir++) {
                    int curX = dirX[dir] + cur.first;
                    int curY = dirY[dir] + cur.second;

                    if(curX < 0 || curY < 0 || curX >=n || curY >=n) continue;
                    if(chk[curX][curY] != 0) continue;
                    if(board[curX][curY] == 1 ) continue;
                    
                    chk[curX][curY] = (chk[cur.first][cur.second] + 1);
                    que.push({curX,curY});
                }
            }

            //6. 모두 처리 했는데, que가 비어있지 않았다면 +1 추가
            if(que.size() != 0 ) timeCnt++;
        }  

        bool isAvailable = true;

        for(int i=0;i<n;i++) {
            for(int j=0;j<n;j++) {
                if(board[i][j] == 1) continue;
                if(chk[i][j] == 0 ) isAvailable = false;
            }
        }

        if(isAvailable) {
            res = min(res, timeCnt);
        }
    } while (next_permutation(forLoop.begin(),forLoop.end()));


    if(res == 987654321 ) {
        cout<<-1<<endl;
    } else {
        cout<<res<<endl;
    }

    return 0;
}