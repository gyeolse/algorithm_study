//1759번. 암호 만들기

#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

/*
    1. 재귀 문제. check 함수는 이해할 수 있었는데, go 함수 다음으로 가는 조건을
        이해할 수 없었음.
    2. 왜 마지막이 두 개 함수로 나눴느냐
    선택하는 경우/ 선택하지 않는 경우.
    abcd로 되어있을 때
    a - (0) (x)
        go_1759(n,alpha,password+alpha[i],i+1); //idx를 하나 더해줌.
        go_1759(n,alpha,password,idx+1); //선택하지 않은 것도 idx는 더해주어야함.
        
    b - (0) (x)
    c - (0) (x)
    d - (0) (x)
*/
//재귀문제 3가지 기억하자
// (1) 불가능한 경우
// (2) 정답인 경우
// (3) 다음 순서를 찾는 경우

using namespace std;

vector <char> alpha;
string password;

//조건 성립이 하는지 하지 않는지
bool check(string password){
    //password 전체에서, 자음의 갯수가 2개 이상인지 확인. 모음의 갯수 1개 이상인지 확인
    int ja = 0;
    int mo = 0;
    for(char x: password){ //char x형으로 선언함. for문 이거 익숙해져야함. 
        if(x=='a'||x=='e'||x=='i'||x=='o'||x=='u'){
            mo++;
        }
        else{
            ja++;
        }
    }
    if(ja>=2 && mo >=1){
        return true;
    }
    else {
        return false;
    }
}

//n : 만들어야 하는 길이, alpha : 주어진 알파벳, password : 현재 암호, i : 현재 idx
void go_1759(int n,vector <char> &alpha, string password, int idx){
    //정답인 경우
    if(password.length() == n){
        if(check(password)){
            cout<<password<<'\n';
        }
        return; //아ㅏ....
    }
    //불가능한 경우 1. 만들어야하는 길이보다 idx가 더 클 때
    if(idx>=alpha.size()) return;

    //다음 경우. 약간 이해가 안감.
    //알파벳을 사용하는 경우/ 하지 않는 경우이므로 두 가지 경우임
    go_1759(n,alpha,password+alpha[idx],idx+1); //사용한 경우
    go_1759(n,alpha,password,idx+1); //사용하지 않은 것도 결정한 것.

}

int main(void)
{
    int l,c; //l은 출력할 갯수, c는 주어지는 갯수
    cin>>l>>c;
    vector<char> alpha_(c);

    for(int i=0;i<c;i++){
        cin>>alpha_[i];
    }
    
    sort(alpha_.begin(),alpha_.end()); //sort하는 과정

    go_1759(l,alpha_,"",0);
    return 0;
}
