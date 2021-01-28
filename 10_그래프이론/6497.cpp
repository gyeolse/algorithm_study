/**
 * 크루스칼 알고리즘으로 풀면 되는 문제이다.
 * 따라서, findParent, unionParnt 구현하고, 그 뒤로 MST를 구하면 해결되는 문제이다. 
 * 맞왜틀 너무 혐오스러웠다.
 * 입력을 이상하게 받는 문제.... while(1)로 계속 n,m으로 받는 건데 문제 해석을 내가 잘 못했다.
 * 
*/

#include <bits/stdc++.h>
#define MAX 200000
using namespace std;
int n,m;
int parent[MAX]; //parent 테이블

//결론 : 모두 연결되어 있는 MST를 만들고, 절약할 최대 비용을 구해라 
int findParent(int x) {
    if(x==parent[x]) return x;
    return parent[x] = findParent(parent[x]);
}

void unionParent(int a, int b) {
    a = findParent(a);
    b = findParent(b);
    if(a>b) parent[a] = b;
    else parent[b] = a;
}

int main() {
    ios::sync_with_stdio(false); cin.tie(NULL);
    while(1) {
        int res = 0;
        int init_value = 0;
        vector<pair<int,pair<int,int>>> edges;

        cin>>n>>m;        

        if(n==0 && m==0) break;

        for(int i=0;i<m;i++) {
            int x,y,z;
            cin>>x>>y>>z;
            edges.push_back({z,{x,y}}); //cost, x, y
            init_value += z;
        }

        //1. cost 순으로 정렬
        sort(edges.begin(),edges.end());

        //2. 자기 자신을 바라보게 업데이트
        for(int i=1;i<=n;i++) {
            parent[i] = i;
        }

        //3. 크루스칼
        for(int i=0;i<edges.size();i++) {
            int cost = edges[i].first;
            int a = edges[i].second.first;
            int b = edges[i].second.second;

            if(findParent(a) != findParent(b)) {
                unionParent(a,b);
                res += cost;
            }              
        }

        cout<<(init_value-res)<<"\n";
    }
    return 0;
}