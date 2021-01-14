//N-Queen. 백트래킹_2번째
#include <iostream>
using namespace std;
int N;
int ans=0;

bool a[15][15];
//각 배열을 추가해서 풀기_2
bool check_col[15];
bool check_dig[40];
bool check_dig_2[40];

//대각선 별로, 대각선에 번호를 매김. r+c

//check 함수 : 놓을 수 있는 자리인지
bool check(int r, int c){
    if(check_col[c]){
        return false;
    }
    if(check_dig[r+c]){ 
        return false;
    }
    if(check_dig_2[r-c+N]){
        return false;
    }
    return true;
}

//calc 함수 : 퀸 자리 지정하기
int calc(int r){
    if(r==N){
        return 1;
    }
    int cnt = 0;

    for(int c=0;c<N;c++){
        if(check(r,c)){
            //놓을 수 있게 처리
            check_dig[r+c]=true;
            check_dig_2[r-c+N] =true;
            check_col[c]=true;
            a[r][c]=true;
            cnt+=calc(r+1);
            //그 전상태로 돌려줌.
            check_dig[r+c]=false;
            check_dig_2[r-c+N] =false;
            check_col[c]=false;
            a[r][c]=false;
        }
     
    }

    return cnt;
}


int main(void){
    cin>>N;
    cout<<calc(0)<<"\n";
    return 0;
}