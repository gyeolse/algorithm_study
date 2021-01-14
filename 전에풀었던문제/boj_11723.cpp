//11723번. 집합
#include <iostream>
#include <string>
using namespace std;
string s; //string 입력
int n; //case
int MAX=20; //20으로 세팅
int input=0; //초기화
int x;
int main(void){
    cin.tie(NULL);
    ios::sync_with_stdio(false);
    cin>>n;
//add, remove, check, toggle, all, empty
    for(int i=0;i<n;i++){
        cin>>s;
        //x-- 해주는 이유 : bitset이 0~부터 시작이라 해당 자리에 넣으려면 -1 해주어야 함.
        if(s=="add"){
            cin>>x;
            x--; 
            input = (input|(1<<x));
        }

        else if(s=="remove") {
            cin>>x;
            x--;
            input = (input & ~(1<<x));
        }

        else if(s=="check") {
            cin>>x;
            x--;
            int temp = (input & (1<<x));
            if (temp)
                cout<<1<<'\n';
            else
                cout<<0<<'\n';
        }

        else if(s=="toggle") {
            cin>>x;
            x--;
            input = (input^(1<<x));
        }

        else if(s=="all") {
            //틀린 부분
            input=(1<<MAX)-1; //강의에서 말했던 부분. 전체를 1로 세팅한 것의 -1 임.
        }

        else if(s=="empty") {
            input = 0;
        }
    }
    return 0;
}

