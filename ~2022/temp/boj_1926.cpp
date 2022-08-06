#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;
#define X first
#define Y second
//define 뒤에 ; 안들어간다. 이거때문에 오류 오지게 찾았다 ㅅㅂ

int arr[502][502];
bool visit[502][502];
int dirX[4]={1,0,-1,0};
int dirY[4]={0,1,0,-1};

int n,m;

//그림이 하나도 없는 경우, 가장 넓은 그림의 넓이는 0
int main(void){
    cin.tie(0);
    ios::sync_with_stdio(false);

    cin>>n>>m;
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            cin>>arr[i][j];
        }
    }

    int picCount=0; //그림의 갯수
    int picMax=0; //그림의 넓이
//queue에 첫번째 값 넣기    
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            if(arr[i][j]==0||visit[i][j]==true) continue; // 0이거나 방문하면 넘어가기
            picCount++; //여기서 count++를 한다. 아. 새로운 시작이란 뜻이니까 여기서 하면 되는구나. 생각해보면 간단한데
            queue<pair<int,int>> que; //que 선언을 해준다. 
            visit[i][j]=true;
            que.push({i,j});
            int area=0; //0으로 시작
            while(!que.empty()){
                area++; //면적이 1증가
                pair<int,int> cur = que.front(); que.pop(); //cur.X, cur.Y로 접근
                for(int k=0;k<4;k++){
                    int nx = cur.first + dirX[k];
                    int ny = cur.second + dirY[k];
                    if(nx<0||nx>=n||ny<0||ny>=m) continue;
                    if(visit[nx][ny] || arr[nx][ny]!=1) continue;
                    visit[nx][ny]=true;
                    que.push({nx,ny});
                }
            }
            //max를 구분해주는 함수
            picMax=max(picMax,area);
        }
    }
    cout<<picCount<<"\n"<<picMax;
    return 0;
}