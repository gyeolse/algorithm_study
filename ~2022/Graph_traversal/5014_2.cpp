#include <bits/stdc++.h>
using namespace std;

int F,S,G,U,D; //총 F층, 현재 S층, 사무실은 G층, Up, Down

int stairs[1000000];
int visit[1000000];

int main() {
    cin.tie(NULL); ios::sync_with_stdio(false);
    cin>>F>>S>>G>>U>>D;
    queue<int> que;
    que.push(S); //현재 S층
    visit[S] = 1;
    while(!que.empty()){
        int cur = que.front(); que.pop();
        int arr[2] = {cur+U,cur-D}; //up and down
        for(int i=0;i<2;i++){
            if(arr[i]>F||arr[i]<=0) continue; //같은 실수를 또;
            if(visit[arr[i]]!=0) continue;
            visit[arr[i]] = visit[cur] + 1;
            que.push(arr[i]);
        }
    }    
    if(visit[G]==0) cout<<"use the stairs";
    else cout<<(visit[G]-1);
    return 0;
}