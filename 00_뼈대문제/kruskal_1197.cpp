#include <bits/stdc++.h>
using namespace std;
#define MAX 10001

int parent[MAX];
int v, e;

// findParent
int findParent(int x) {
    if (parent[x] == x) return x;
    return parent[x] = findParent(parent[x]);
}

// unionParent 
void unionParent(int a, int b) {
    a = findParent(a);
    b = findParent(b);
    if (a > b) parent[a] = b;
    else parent[b] = a;
}

int main() {

    vector<pair<int, pair<int, int>>> vec;
    int res = 0;

    for (int i = 1;i <= MAX;i++) {
        parent[i] = i;
    }

    cin >> v >> e;
    for (int i = 0;i < e;i++) {
        int a, b, c;
        cin >> a >> b >> c;
        vec.push_back({ c,{a,b} });
    }

    sort(vec.begin(), vec.end());

    for (int i = 0;i < vec.size();i++) {
        int cost = vec[i].first;
        int a = vec[i].second.first;
        int b = vec[i].second.second;

        if (findParent(a) != findParent(b)) {
            unionParent(a, b);
            res += cost;
        }
    }
    cout << res << "\n";
    return 0;
}