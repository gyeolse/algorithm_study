#include <bits/stdc++.h>
using namespace std;
#define MAX 1000
#define INF 987654321

int n, e;
int v1, v2;
int oneToV1, oneToV2, v1ToV2, v2ToN, v1ToN;

vector<pair<int, int>> graph[MAX];
int dist[MAX];

int dijkstra(int start, int end) {
    int res=0;

    //1. INF 초기화
    fill_n(dist, MAX, INF);
    
    //1. 시작점 초기화
    priority_queue <pair<int, int>> pq;
    dist[start] = 0;
    pq.push({ 0,start });

    //2. 큐 수행
    while (!pq.empty()) {
        auto cur = pq.top(); pq.pop();
        int curDist = -cur.first;
        int curNode = cur.second;
        //!!! 전에 처리한적있는지 확인
        if (dist[curNode] < curDist) continue;

        //3. 현 노드에 연결된 갯수만큼. i에 1넣고 포문 안됨!
        for (int i = 0;i < graph[curNode].size();i++) {
            int cost = curDist + graph[curNode][i].second;
            //4. 비교
            if (cost < dist[graph[curNode][i].first]) {
                dist[graph[curNode][i].first] = cost;
                pq.push({ -cost,graph[curNode][i].first});
            }
        }
    }

    //노드와 노드간의 최단거리 찾기
    res = dist[end];
    return res;
}

int main() {
    ios::sync_with_stdio(false); cin.tie(NULL);
    cin >> n >> e;
    for (int i = 0;i < e;i++) {
        int a, b, c; //a,b 사이 양방향 거리 c
        cin >> a >> b >> c;
        graph[a].push_back({ b,c });
        graph[b].push_back({ a,c });
    }

    cin>>v1>>v2;


    //2. 다익스트라 알고리즘
    //1. 1에서 v1, v2로 가는 것을 구하기 
    oneToV1 = dijkstra(1, v1);
    oneToV2 = dijkstra(1, v2);
    //2. v1에서 v2로 가는 것을 구하기
    v1ToV2 = dijkstra(v1,v2);

    //3. v1에서 n으로 가는 것을 구하기
    v1ToN = dijkstra(v1,n);

    //4. v2에서 n으로 가는 것을 구하기 
    v2ToN = dijkstra(v2,n);

    //3. 출력
    int res = min((oneToV1 + v1ToV2 + v2ToN), (oneToV2 + v1ToV2 + v1ToN));
    if(res==INF || res < 0 ) {
        cout<<"-1"<<"\n"; //오버플로우를 고려해야했다.
    } else {
        cout<<res<<"\n";
    }
    // cout<<min((oneToV1 + v1ToV2 + v2ToN), (oneToV2 + v1ToV2 + v1ToN))<<"\n";

    //3. 출력
    // for(int i=1;i<=n;i++){
    //     cout<<dist[i]<<" ";
    // }
    return 0;
}