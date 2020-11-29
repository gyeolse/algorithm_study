#include <bits/stdc++.h>
using namespace std;

int stairs[1000000];
int visit[1000000]; //해당 칸까지 가는데 드는 최소 횟수 저장. 0일때와 아닐때 구분 필요

int total,current,office,up,down; //F: 총 S: 현재, G: 사무실층, U:몇층만큼 올라가기 가능?, D:몇층만큼 내려가기 가능?
int main() {
    cin>>total>>current>>office>>up>>down; //10 1 10 2 1
    queue<int> que;
    //1. 현재 층에서 일단 시작하게 됨.
    visit[current] = 1;
    que.push(current);

    while(!que.empty()){
        int cur = que.front(); que.pop(); //현재 층이 들어가있음.
        int arr[2] = {cur+up,cur-down};
        for(int i=0;i<2;i++){
            int temp = arr[i];
            if(temp>total || temp<=0) continue;
            if(visit[temp]!=0 ) continue;
            visit[temp] = visit[cur] + 1;
            que.push(temp);
        }
    }

    if(visit[office]==0) cout<<"use the stairs";
    else cout<<(visit[office]-1); //-1을 하는 이유. ~번 이동인데, 처음 설정해줄때, 1로 두고 설정해줌. 때문에 -1을 해주어야함. 
    return 0;
}