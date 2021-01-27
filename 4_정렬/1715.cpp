#include <bits/stdc++.h>
using namespace std;
int n;
priority_queue<int> pq;
vector<int> arr;

int main() {
    cin.tie(NULL); ios::sync_with_stdio(false);
    cin >> n;
    for (int i = 0;i < n;i++) {
        int x; cin >> x; pq.push(-x);
    }

    //1. 항상 최소값을 꺼내는 것이 최적이다. ㅅㅂ
    int totalCount = 0;
    while(pq.size()!=1) { //1이 되는 경우 -> 제일 마지막 값일 때
        int x = -pq.top(); pq.pop();
        int y = -pq.top(); pq.pop();        
        totalCount += x;
        totalCount += y;
        int next_ = x+y;
        pq.push(-next_);
    }

    cout<<totalCount<<"\n";
    return 0;
}