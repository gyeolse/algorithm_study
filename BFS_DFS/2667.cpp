//단지번호 붙이기
#include <bits/stdc++.h>
using namespace std;

int board[30][30]; //범위를 너무 적게 지정해줘서 틀린건 또 처음이다 어이가 없다
int visit[30][30];
int n=0;
string s;
//direction
int dirX[4] = {1,0,-1,0};
int dirY[4] = {0,1,0,-1};

int main() {
    cin>>n;
    for(int i=0;i<n;i++){
        cin>>s;
        for(int j=0;j<n;j++){
            if(s[j]=='1') board[i][j] = 1;
        }
    }

    queue<pair<int,int>> que;
    int cnt = 0;
    int area = 0;
    vector<int> res;
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            if(visit[i][j]==0 && board[i][j] == 1) {
                que.push({i,j});
                cnt++;
                visit[i][j] = cnt; 
                while(!que.empty()) {
                    area++;
                    pair<int,int> cur = que.front(); que.pop();
                    for(int dir=0;dir<4;dir++){
                        int curX = cur.first + dirX[dir];
                        int curY = cur.second + dirY[dir];
                        if(visit[curX][curY]>0 || board[curX][curY]==0) continue;
                        if(curX<0 || curX>=n || curY<0 || curY>=n) continue;
                        que.push({curX,curY});
                        visit[curX][curY] = cnt;
                    }
                }

                if(area!=0){
                    res.push_back(area);
                    area=0;
                }            
            }
        }
    }

    sort(res.begin(),res.end());
    cout<<cnt<<"\n";
    for(int i=0;i<cnt;i++){
        cout<<res[i]<<"\n";
    }

    return 0;
}