#include <bits/stdc++.h>
#define MAX 100001

using namespace std;
int n,m; //집의 갯수, 길의 갯수
vector<pair<int,pair<int,int>>> edges; //길 정보
int parent[MAX];

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
    cin.tie(NULL); ios::sync_with_stdio(false);
    cin>>n>>m;
    for(int i=0;i<m;i++){
        int a,b,cost;
        cin>>a>>b>>cost;
        edges.push_back({cost,{a,b}});
    }

    vector<int> res;

    //1. 자기 자신 == 부모 
    for(int i=1;i<=n;i++) {
        parent[i] = i;
    }

    //2. 정렬
    sort(edges.begin(),edges.end());

    //3. 크루스칼 알고리즘 시행
    for(int i=0;i<m;i++) {
        int cost = edges[i].first;
        int a = edges[i].second.first;
        int b = edges[i].second.second;

        //4. 부모가 다른 경우 
        if(findParent(a) != findParent(b)) {
            //5. unionParent 실행
            unionParent(a,b);
            //6. result에 더함
            res.push_back(cost);
        }
    }

    //7. vector의 max_element를 삭제한 후, vector 값을 모두 더한 것이 답
    int m_ = *max_element(res.begin(),res.end());
    int totalRes = 0;
    for(int i=0;i<res.size();i++) {
        totalRes += res[i];        
    }
    cout<<totalRes-m_<<"\n";
    return 0;
}