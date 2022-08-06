#include <bits/stdc++.h>
using namespace std;
#define INF 987654321
#define MAX 30001
vector<pair<int,int>> graph[MAX]; //그래프 정보
int dist[MAX];
int n,m,c;

void solve_problem(int start) {
    //pq -> {노드 도달까지 걸린 시간, 노드}
    priority_queue<pair<int,int>> pq;
    dist[start] = 0;
    pq.push({0, start});

    //1. pq가 비어 있을 떄 까지 반복한다.
    while(!pq.empty()){
    //2. 제일 작은 값을 꺼낸다
    auto cur = pq.top(); pq.pop();
    int curDist = -cur.first;
    int now = cur.second;

    // !!! 이미 처리된 경우, 무시하는 로직을 추가해야함.
    if(dist[now] < curDist ) continue;

    //3. 현재의 dist와 원래 세팅된 dist를 비교해서, min값을 넣는다.
    for(int i=0;i<graph[now].size();i++) {
        int cost = curDist + graph[now][i].second;

        // !!! 현재노드를 거쳐서 다른 노드로 이동하는 것이 짧은 경우
        // !!! 그럴 경우에만 push 해줄 것이므로, stl 쓰기보다 if문 처리해주어야함
        if(cost < dist[graph[now][i].first]) {
            dist[graph[now][i].first] = cost;
            //4. 다음 값을 pq에 넣는다.
            pq.push({-cost,graph[now][i].first});
        }
    }
    }
}

int main() {
    //1. 입력
    cin>>n>>m>>c;
    for(int i=0;i<m;i++){
        int a,b,c; //도시의 개수, 통로의 개수, 메시지를 보내고자 하는 도시
        cin>>a>>b>>c;
        graph[a].push_back({b,c});        
    }

    //2. 무한으로 초기화   
    fill_n(dist,MAX,INF);

    //3. 시작점을 넣고, 실행
    solve_problem(c);

    //4. 출력
    int cnt=0;
    int cityTime=0;

    for(int i=1;i<=n;i++){
        if(dist[i]!=INF && i!=c) {
            cnt++;
            cityTime = max(dist[i],cityTime);
        }
    }

    cout<<cnt<<" "<<cityTime<<"\n";
    return 0;
}