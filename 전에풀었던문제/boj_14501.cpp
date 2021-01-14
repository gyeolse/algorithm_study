//14501. 퇴사
#include <iostream>

using namespace std;

/*
    틀림. 재귀문제 진짜 조건 정해주는게 너무 빡친다...
    다 풀어놓으면 쉬워보이는데, 막상 풀고나면 너무 어렵다....
    개 열받는다....
    
    재귀. 0,1,2,3 순서대로
    0. 무엇을 선택할지/말지
    1. 불가능한 경우 : 더이상X, 조건 위배, 할수있는선택X
    2. 정답인 경우
    3. 다음 경우
*/
int n; //n일 이후로는 뭘 할수가 없음
int T[1000]; //시간 일정
int P[1000]; //금액
int answer=0;
//날짜, 금액, day
void go_14501(int day, int sum){
//2 정답인 경우
    if(day==n+1){
        if(answer<sum){ //지금까지의 수익보다 큰 경우에만
            answer =sum;
            return;
        }
    }
//1 불가. day가 n보다 클 경우
    if(day>n){
        return;
    }

    go_14501(day+T[day],sum+P[day]); //선택 0
    go_14501(day+1,sum); //선택 X
}
int main(){
    cin>>n;
    for(int i=1;i<=n;i++){
        cin>>T[i]>>P[i];
    }
    go_14501(1,0);
    cout<<answer<<"\n";
    return 0;
}