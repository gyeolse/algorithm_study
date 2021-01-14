#include <iostream>
using namespace std;

int main(void){
    int num;
    cin>>num;

    for(int i=0;i<num;i++){
        int m,n,x,y;
        bool isOK=false;
        cin>>m>>n>>x>>y;
        //x=3, y=5라면 x=2, y=4가 됨.
        x-=1;
        y-=1;
//m과 n은 mod값을 위한 기준이므로 그대로 냅둬도 됨
//그 때, -1만큼 해줘야, 0,0 ~ m-1,n-1 까지 loop 돌고, 마지막에 +1을 해주면 답이 나오게 됨
//일단 for문은 m*n만큼 돈다. 하지만, for문 내에서 돌면서, m만큼 증가함. 시작은 x에서 부터 시작을 해야함 
//왜 x부터 시작하냐, x부터 +m 사이클이 곧 고정한다는 거니까.
//*** x와 y를 1씩 빼주지 않고, idx를 1을 더하고 출력하지 않아도, 
//테스트케이스의 답은 나온다. 하지만, 틀렸다고 나온다. 처음에 이렇게 했었는데

        for(int idx=x;idx<(m*n);idx+=m){
            if(idx%n==y){
                cout<<idx+1<<"\n";
                isOK= true;   
                break;    
            }
        }
        if(isOK==false){
            cout<<-1<<"\n";
        }
    }
    return 0;
}