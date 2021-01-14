//9095번. 1,2,3 더하기.
/*
    재귀함수 풀기
    재귀로 풀 때 3가지 찾아서 접근할 것. (각각 번호 표시하기!) 불.정.다음
    (1) 불가능한 경우
    (2) 정답을 찾은 경우
    (3) 다음 순서를 호출하는 경우

*/
#include <iostream>
#include <algorithm>

using namespace std;
int T; //test case
int sum;    

int go (int sum,int goal){
//1 불
    if(sum>goal) return 0;
//2 정
    if(sum==goal) return 1;
//3 다음
    int now = 0;
    
    //다음 단계로 갈 수 있는 세 가지 경우 (1,2,3)
    for(int i=1;i<=3;i++){
        now+=go(i+sum,goal);
        //매우 간결함. n=4일 때를 예시로 생각하면서 그려보면 편하게 이해할 수 있을 것.
        
    }
    return now;
}

int main(void){
    cin.tie(NULL);
    ios::sync_with_stdio(false);
    cin>>T;

    for(int i=0;i<T;i++){
        int n;
        cin>>n;
        cout<<go(0,n)<<"\n";
    }

    return 0;
}