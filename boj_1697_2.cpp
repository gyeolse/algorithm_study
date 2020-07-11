#include <iostream>
#include <algorithm>
#include <cstring>
#include <queue>
using namespace std;
int n,k;

int dist[100001]; //�Ÿ� ���

int main(void){
    cin>>n>>k;
    memset(dist,-1,sizeof(dist)); //-1�� �ʱ�ȭ
    dist[n]=0; //�ش� idx 1�� �ʱ�ȭ
    queue<int> que;
    que.push(n);

//while���� ������ �޸� ��. dist[k]�� -1�� �ƴϸ�, �ּҷ� ã�Ҵٴ� ���� �ǹ���
    while(dist[k]==-1){
        int cur = que.front(); que.pop();
        
        //cur+1, cur-1, cur*2 3����
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