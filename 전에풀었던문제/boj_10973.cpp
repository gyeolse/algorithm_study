//10973번. 이전 순열

/*
    10972의 접근법과 같다. 등호만 반대로 하면 됨.
    vecotr와 algorithm을 이용해서 함. 훨~~~씬 편함.
    실수1. vector의 크기 지정을 해줬어야했는데 하지 못함. 다음부터 실수하지 말 것.
*/

#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int test_case;

int main(void){

    cin>>test_case;
    vector<int> vec(test_case); //실수1. vector의 크기를 미리 지정해주어야 함..... 몰랐다.

    for(int i=0;i<test_case;i++){
        cin>>vec[i];
    }

    if(prev_permutation(vec.begin(),vec.end())==1){
        for(int i=0;i<test_case;i++){
            cout<<vec[i]<<" ";
        }
    }
    else{
        cout<<-1<<'\n';
    }

    return 0;
}