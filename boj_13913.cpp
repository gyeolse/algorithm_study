#include <iostream>
#include <queue>
#include <algorithm>
#include <cstring>
#include <stack>

using namespace std;

//2*x�� ��찡 �ֱ� ������
int dist[200001]; //�湮Ƚ��
bool check[200001]; //true ,false ���� �ִ´ٰ� ����
int from[200001];


int main(void){

    void init();
    int n,k;
    cin>>n>>k;

//�ʱ�ȭ
    check[n] = true;
    dist[n]=0;
    queue<int> que;
    que.push(n);
//bfs
    while(!que.empty()){
        int now = que.front(); //���� ť ��. 
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
                //�湮. +1. dist �ְ�. enque
                que.push(now*2);
                check[now*2]= true;

                dist[now*2] = dist[now]+1;
                from[now*2] = now;
            }
        }

    }
    cout<<dist[k]<<"\n";

    stack <int> stk;
    //���ÿ��� ���ʴ�� �׾��ָ鼭, �ְ� ���߿� pop�� �ѹ���

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