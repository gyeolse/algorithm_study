#include <iostream>
#include <algorithm>
#include <queue>

using namespace std;

int dirY[4] = {1,0,-1,0};
int dirX[4] = {0,1,0,-1};
//vector을 이용해서, 몇 초에 움직일 건지 넣어야함
vector<pair<int, char>> turnInfo;
int inputNum;
int appleNum;
int changeNum;
int arr[101][101];

int changeDirection(int direction, char c){
    if(c=='L') direction = (direction==0) ? 3 : direction -1;
    else direction = (direction+1) %4; 
    return direction;
}

int main(void){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cin>>inputNum>>appleNum;
    for(int i=0;i<appleNum;i++){
        int tempX, tempY;
        cin>>tempX>>tempY;
        arr[tempX][tempY]=1; //1은 사과가 있음
    }
    cin>>changeNum;
    for(int i=0;i<changeNum;i++){
        int temp;
        char c;
        cin>>temp>>c;

        turnInfo.push_back({temp,c});
    }
    //simulation start 
    int x=1, y=1;
    arr[x][y] = 2; //뱀의 위치를 2로 표시한다. 
    int direction  = 0;
    int t = 0;
    int idx=0;
    queue<pair<int,int>> que; //뱀이 차지하고 있는 위치 정보
    que.push({x,y});

    while(1){
        int nx = x + dirX[direction];
        int ny = y + dirY[direction];

        //뱀의 몸통이 없고, 맵 범위 안에 있는 경우
        if(1<=nx && nx<= inputNum && 1<=ny && ny <=inputNum && arr[nx][ny]!=2){
            //사과가 없는 경우
            if(arr[nx][ny]==0){
                arr[nx][ny] = 2;
                que.push({nx,ny});
                int px = que.front().first;
                int py = que.front().second;
                que.pop();
                arr[px][py] = 0;
            }
            //사과가 있는 경우
            if(arr[nx][ny]==1){
                arr[nx][ny] = 2;
                que.push({nx,ny});
            }
        }
        else {
            t+=1;
            break;
        }

        x = nx;
        y = ny;
        t +=1;
        if(idx< changeNum&& t==turnInfo[idx].first){ //회전할 시간일 경우 
            direction = changeDirection(direction,turnInfo[idx].second);
            idx+=1;
        }
    }

    cout<<t<<endl;
    return 0;
}