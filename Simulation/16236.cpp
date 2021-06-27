#include <bits/stdc++.h>
using namespace std;
/**
 * 우선순위 큐 사용 : priority_queue <구조체, 컨테이너, 비교 구조체> pq;
*/
int board[21][21]; // input
int chk[21][21];
int n;
int dirX[4] = { -1,0,1,0 };
int dirY[4] = { 0,1,0,-1 };

struct fish
{
    int x;
    int y;
    int dist;
};

//비교함수 정의 : a가 b보다 크다면, true를 리턴해서 swap 진행함
//가장 작은 원소가 제일 앞에 가게 된다.
struct compare {
    bool operator()(fish a, fish b) {
        if (a.dist == b.dist) {
            if (a.x == b.x) {
                return a.y > b.y;
            }
            return a.x > b.x;
        }
        return a.dist > b.dist;
    }
};

int main() {
    cin.tie(NULL); ios::sync_with_stdio(false);
    pair<int,int> sharkLocation;
    int sharkSize = 2;
    int time = 0;
    int eatFish = 0; //상어 클 지 말지 결정
    queue<fish> que;

    cin>>n;
    for (int i = 0;i < n;i++) {
        for (int j = 0;j < n;j++) {
            cin >> board[i][j];
            if (board[i][j] == 9) {
                board[i][j] = 0;
                que.push({i,j,0});
                chk[i][j] = true;

            }
        }
    }

    //1.
    while(1) {
        priority_queue<fish, vector<fish>, compare> pq; //우선순위 큐 정의

        //bfs 탐색
        while(!que.empty()) {
            //1. 먹을 수 있는 고기 탐색
            auto cur = que.front(); que.pop();
            for(int dir=0;dir<4;dir++){
                int curX = cur.x + dirX[dir];
                int curY = cur.y + dirY[dir];

                if(curX<0 || curY<0 || curX >=n || curY>=n) continue;
                if(board[curX][curY] > sharkSize || chk[curX][curY] != 0 ) continue;
                que.push({curX,curY,cur.dist+1});
                chk[curX][curY] = 1;
                //2. 먹을 수 있다면 pq에 저장
                if(board[curX][curY] < sharkSize && board[curX][curY] !=0) {
                    pq.push({curX,curY,cur.dist+1});
                }
            }
        }

        //3. chk 배열 초기화 
        memset(chk,0,sizeof(chk));

        //4. pq가 비어있지 않다면, 물고기 먹기를 수행하기
        if(!pq.empty()) {
            fish cur = pq.top(); pq.pop();
            board[cur.x][cur.y] = 0; //물고기 먹은 후, 0 설정

            //먹은 물고기 처리
            eatFish++;

            //시간 처리 
            time = cur.dist; //이게 잘 이해가 안간다. 

            //다음 아기 상어의 위치 push (다시 que의 시작을 위해서)
            que.push({cur.x,cur.y,cur.dist});
            chk[cur.x][cur.y] = 1;
        }
        else { //먹을 수 있는 상어가 없음
            cout<<time<<"\n";
            break;
        }

        //먹은 갯수, 상어 크기 같으면, 상어 크기 ++하고 먹은 갯수 초기화
        if(eatFish == sharkSize) {
            sharkSize++;
            eatFish = 0;
        }
    }

    return 0;
}