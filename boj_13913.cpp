#include <iostream>
#include <queue>
#include <algorithm>
#include <cstring>
#include <stack>

using namespace std;

//2*x의 경우가 있기 때문에
int dist[200001]; //방문횟수
bool check[200001]; //true ,false 값을 넣는다고 생각
int from[200001];


int main(void){

    void init();
    int n,k;
    cin>>n>>k;

//초기화
    check[n] = true;
    dist[n]=0;
    queue<int> que;
    que.push(n);
//bfs
    while(!que.empty()){
        int now = que.front(); //현재 큐 값. 
        que.pop();
        if(now-1>=0){
            if(check[now-1]!=true){
                que.push(now-1);
                check[now-1]= true;
                dist[now-1] = dist[now]+1;            
                from[now-1] = now;

        }
        }
        if(now+1<200000){
            if(check[now+1]!=true){
                que.push(now+1);
                check[now+1]= true;

                dist[now+1] = dist[now]+1;
                from[now+1] = now;

            }
        }
        if(now*2<200000){
            if(check[now*2]!=true){
                //방문. +1. dist 넣고. enque
                que.push(now*2);
                check[now*2]= true;

                dist[now*2] = dist[now]+1;
                from[now*2] = now;
            }
        }

    }
    cout<<dist[k]<<"\n";

    stack <int> stk;
    //스택에서 차례대로 쌓아주면서, 넣고 나중에 pop은 한번에

/*
    for(int i=k;i!=n;i=from[i]){
        stk.push(i);
    }
    stk.push(n);
    while(!stk.empty()){
        cout<<stk.top()<<" ";
        stk.pop();
    }
*/
   return 0;
}

//aksdkfjalsdjf;aklsdjf;asdf