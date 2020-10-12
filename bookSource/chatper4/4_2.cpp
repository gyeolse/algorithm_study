// 4-2 시각
// 24 * 60 * 60 = 86400초(가지) 경우의 수 

/* .py 의 경우 -- 문자열로 바꿔서 3이 포함된 경우 ++ 함
    전형적인 브루트 포스 유형 ( 완전 탐색 유형 )
    c++ 
    - i, j, k를 mod 하거나 나눠서 3이 되는 경우가 즉 3이 포함되어 있는 것.
    - 직관적으로 생각하도록 연습하자
*/

#include <iostream>
#include <string>
using namespace std;

int n;
int res;

int main(void){
    cin>>n;

    for(int i=0;i<=n;i++){
        for(int j=0;j<60;j++){
            for(int k=0;k<60;k++){
                if(i%10 == 3 || j/10 ==3 || j%10 ==3 || k/10 ==3 || k%10==3) res++;
            }
        }
    }

    cout<<res;

}