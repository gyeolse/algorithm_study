#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
#include <string>
using namespace std;

//다차원 배열에서의 거리 측정하기. 
//flood fill
int n,m;

string board[102]; //board 배열 선언. string 자체가 char로 이루어진 배열이기 때문에 [][]이렇게 접근을 하는 것이 가능하다는 것을 간과하고 있었음
int result[102][102];
int dirX[4] = {1,0,-1,0};
int dirY[4] = {0,1,0,-1};

int main(void){
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin>>n>>m;
    for(int i=0;i<n;i++){
        cin>>board[i];
    }
    for(int i=0;i<n;i++){
        fill(result[i],result[i]+m,-1); //fill 함수. 초기화함수. memset이랑 하는 역할이 비슷하다고 생각하면 됨. 
    }
//첫번째 원소로 start
    queue<pair<int,int>> que;
    que.push({0,0});
    result[0][0]=0; //result 배열을 쓰는 대신에, visit배열을 쓸 필요가 없어짐 왜냐하면, -1로 초기에 선언을 해주었기 때문에, -1은 미방문을 뜻하기 때문임.

    while(!que.empty()){
        pair<int,int> cur = que.front(); que.pop();

        for(int i=0;i<4;i++){
            int nX = cur.first + dirX[i];
            int nY = cur.second + dirY[i];
            if(nX<0||nX>=n||nY<0||nY>=m) continue;
            if(result[nX][nY]>=0||board[nX][nY]!='1') continue;
            result[nX][nY] = result[cur.first][cur.second] + 1; //바로 전 값보다 + 1 한 값이 되겠지.
            que.push({nX,nY});
        }
    }
    //queue

    cout<<result[n-1][m-1]+1<<"\n"; //문제에서 처음 시작도 1로 쳐서 1을 더해주는 것이 맞다
    return 0;    
}