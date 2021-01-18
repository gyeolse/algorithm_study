//플로이드-워셜 알고리즘
#include <bits/stdc++.h>
using namespace std;
#define MAX 200
#define INF 987654321
int n,m;
int graph[MAX][MAX];

int main() {
    ios::sync_with_stdio(false); cin.tie(NULL);    
    //1. INF로 초기화, 자기 자신으로 가는 간선 0으로 초기화 
    for(int i=0;i<MAX;i++) {
        fill_n(graph[i],MAX,INF);
    }
    for(int i=0;i<MAX;i++) {
        for(int j=0;j<MAX;j++){
            if(i == j ) { 
                graph[i][j] = 0;
            }
        }
    }
    //2. 입력
    cin>>n>>m;
    for(int i=0;i<m;i++){
        int a,b,c; //a 도시, b 도시, c 비용 
        cin>>a>>b>>c;
        if(graph[a][b] !=INF) {
            graph[a][b] = min(c,graph[a][b]);
        } else {
            graph[a][b] = c;
        }
    }
    //3. 플로이드-워셜 알고리즘 진행
    //1) 해당 노드를 통해서 가는 것이, 기존의 거리보다 빠르다면 변경시켜준다.
    for(int i=1;i<=n;i++){
        for(int j=1;j<=n;j++){
            for(int k=1;k<=n;k++){
                graph[j][k] = min(graph[j][k],graph[j][i]+graph[i][k]);
            }
        }
    }
    //4. 출력
    for(int i=1;i<=n;i++){
        for(int j=1;j<=n;j++){
            if(graph[i][j]==INF) {
                cout<<0<<" ";
            }
            else {
                cout<<graph[i][j]<<" ";
            }
        }
        cout<<"\n";
    }
    return 0;
}