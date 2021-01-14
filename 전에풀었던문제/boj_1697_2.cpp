#include <iostream>
#include <algorithm>
#include <cstring>
#include <queue>
using namespace std;
int n,k;

int dist[100001]; //거리 계산

int main(void){
    cin>>n>>k;
    memset(dist,-1,sizeof(dist)); //-1로 초기화
    dist[n]=0; //해당 idx 1로 초기화
    queue<int> que;
    que.push(n);

//while문의 조건을 달리 함. dist[k]가 -1이 아니면, 최소로 찾았다는 것을 의미함
    while(dist[k]==-1){
        int cur = que.front(); que.pop();
        
        //cur+1, cur-1, cur*2 3가지
        if(dist[cur-1]==-1){
            if(cur-1 < 0 || cur-1 > 100000) continue;
            dist[cur-1] = dist[cur] + 1;
            que.push(cur-1);
        }
        if(dist[cur+1]==-1){
            if(cur+1 < 0 || cur+1 > 100000) continue;            
            dist[cur+1] = dist[cur] + 1;
            que.push(cur+1);
        }
        if(dist[cur*2]==-1){
            if(cur*2 < 0 || cur*2 > 100000) continue;            
            dist[cur*2] = dist[cur] + 1;
            que.push(cur*2);
        }
    }

    cout<<dist[k];
    return 0;
}