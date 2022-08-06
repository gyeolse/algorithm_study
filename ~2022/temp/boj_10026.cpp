#include <queue>
#include <iostream>
using namespace std;
int dist1[100][100]; //정상인
int dist2[100][100];
string s[100];
int n;
int dirX[4] = {1,0,-1,0};
int dirY[4] = {0,1,0,-1};

int main(void){
    cin>>n;
    for(int i=0;i<n;i++){
        cin>>s[i];
        fill(dist1[i],dist1[i]+n,-1); //-1로 초기화
        fill(dist2[i],dist2[i]+n,-1);
    }
    

    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            queue<pair<int,int>> que;             
            if(dist1[i][j]!=-1) continue;
            dist1[i][j] = 0;
            que.push({i,j});
            while(!que.empty()){
                pair<int,int> cur = que.front(); que.pop();
                for(int k=0;k<4;k++){
                    int curX = cur.first + dirX[k];
                    int curY = cur.second + dirY[k];
                    if(curX<0||curX>=n||curY<0||curY>=n) continue;
                    if(dist1[curX][curY]!=-1) continue;
                    if(s[cur.first][cur.second]!=s[curX][curY]) continue;
                    dist1[curX][curY] = dist1[cur.first][cur.second]+1;
                    que.push({curX,curY});
                }
            }
        }
    }

    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            queue<pair<int,int>> que;             
            if(dist2[i][j]!=-1) continue;
            dist2[i][j] = 0;
            que.push({i,j});
            while(!que.empty()){
                pair<int,int> cur = que.front(); que.pop();
                for(int k=0;k<4;k++){
                    int curX = cur.first + dirX[k];
                    int curY = cur.second + dirY[k];
                    if(curX<0||curX>=n||curY<0||curY>=n) continue;
                    if(dist2[curX][curY]!=-1) continue;
                    if((s[cur.first][cur.second]=='R')&& s[curX][curY]=='G'){
                        dist2[curX][curY] = dist2[cur.first][cur.second]+1;
                        que.push({curX,curY});
                    }
                    else if((s[cur.first][cur.second]=='G')&& s[curX][curY]=='R'){
                        dist2[curX][curY] = dist2[cur.first][cur.second]+1;
                        que.push({curX,curY});
                    }
                    else if(s[cur.first][cur.second]!=s[curX][curY]){
                        continue;
                    }
                    else if(s[cur.first][cur.second]==s[curX][curY]){
                        dist2[curX][curY] = dist2[cur.first][cur.second]+1;
                        que.push({curX,curY});
                    }
            }
        }
    }
    }

    int ans1=0;
    int ans2=0;

    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            if(dist1[i][j]==0) ans1++;
            if(dist2[i][j]==0) ans2++;
            
        }
    }

    cout<<ans1<<" "<<ans2;
}