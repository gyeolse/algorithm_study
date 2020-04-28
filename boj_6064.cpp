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
//일단 for문은 m*n만큼 돈다. 하지만, for문 내에서 돌면서, m만큼 증가함. 시작은 x에서 부터 시작을 해야함 
//왜 x부터 시작하냐, x부터 +m 사이클이 곧 고정한다는 거니까.

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