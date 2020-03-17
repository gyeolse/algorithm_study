//1182번. 부분수열의 합
#include <iostream>
using namespace std;

/* 재귀로 풀 때 항상 쓰고 시작하자
    0. (무엇을) 할지 말지
    1. 불가능한 경우 3가지
        (1) 더 이상 호출해도 정답 X 
        (2) 문제 조건 위배
        (3) 더 이상 할 수 있는 선택 X 
    2. 가능한 경우
    3. 다음 경우갈 조건
*/

//전역 변수
int arr[20]; //주어지는 정수
int N,S; //정수의 개수 N, 정수 S
int ans;
//재귀 함수
void go_1182(int sum, int idx) {
    //1 안될때. idx가 총 개수랑 같고, sum이 S랑 다를 때
    //2 답인 경우 sum이 S랑 같고, idx가 총 갯수랑 같을 때
    //예외. 2,-2, 2일때 첫번째 케이스만 돌고 종료되어서는 안됨.
    if(N==idx){
        if(sum == S){
            ans+=1;
        }
        return;
    }
    //3 다음 경우
    go_1182(sum+arr[idx],idx+1); //고르는 경우
    go_1182(sum,idx+1); //고르지 않는 경우
}
int main(void){
    cin.tie(NULL);
    cout.tie(NULL);
    ios::sync_with_stdio(false);

    cin>>N>>S;
    for(int i=0;i<N;i++){
        cin>>arr[i];
    }
//재귀 함수는 한번만 호출
    go_1182(0,0);
    if(S==0) ans-=1; //공집합일 때는 1을 빼준다. 이래나 저래나 한번 돌면 1을 반환하기 때문에
    
    cout<<ans<<"\n";

    return 0;

}