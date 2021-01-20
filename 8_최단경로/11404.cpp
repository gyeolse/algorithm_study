#include <bits/stdc++.h>
using namespace std;
#define MAX 500
#define INF 987654321

int graph[MAX][MAX];
int n,m;

int main() {
    cin.tie(NULL); ios::sync_with_stdio(false);
    cin>>n>>m;

    //init
    for(int i=0;i<MAX;i++){
        for(int j=0;j<MAX;j++){
            if(i==j){
                graph[i][j]=0;
            }
            else {
                graph[i][j] = INF;
            }
        }
    }

    //input
    for(int i=0;i<m;i++){
        int a,b,c;
        cin>>a>>b>>c;
        if(graph[a][b] != INF) {
            graph[a][b] = min(graph[a][b],c);
        }
        else {
            graph[a][b]=c;
        }
    }

    //algorithm
    for(int i=1;i<=n;i++){
        for(int a=1;a<=n;a++){
            for(int b=1;b<=n;b++){
                graph[a][b] = min(graph[a][i]+graph[i][b], graph[a][b]);
            }
        }
    }

    //output
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