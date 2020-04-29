//N-Queen. 백트래킹
#include <iostream>
using namespace std;
int N;
int ans=0;
bool a[15][15];

//check 함수 : 놓을 수 있는 자리인지
bool check(int r, int c){
    // l일직선 방향 체크
    for(int i=0;i<N;i++){
        if(i==r) continue;
        if(a[i][c]){
            return false;
        }
    }
    // \방향 체크 (1,1)이라면 (0,0). (2,2)라면, (1,1) (0,0)....
    int x=r-1;
    int y=c-1;

    while(x>=0 && y>=0){ //x,y 양수일때만 loop
        if(a[x][y]==true){
            return false;
        }
        x-=1;
        y-=1;
    }

    // /방향 체크. (2,2)라면 (1,3) (0,4)
    x=r-1;
    y=c+1;

    while(x>=0 && y<N){ //y의 범위 지정이 y>=0이면 안됨. y<n이어야함. y는 계속 증가하고 있다. 
        if(a[x][y]==true){
            return false;
        }

        x-=1;
        y+=1;
    }

    return true;
}

//calc 함수 : 퀸 자리 지정하기
void calc(int r){
    if(r==N){
        ans +=1;
    }
    for(int c=0;c<N;c++){ //c=column
        a[r][c] = true;
        if(check(r,c)){ //놓을 수 있는 자리인지
            calc(r+1); //재귀
        }
        //if문 내에 진입 못할 경우
        a[r][c]=false;        
    }
}


int main(void){
    cin>>N;
    calc(0);

    cout<<ans<<"\n";

    return 0;
}