#include <bits/stdc++.h>
using namespace std;

int n;
priority_queue<int> pq;
vector<pair<int, int>> vec;
int res = 0;

int main() {
    cin.tie(NULL); ios::sync_with_stdio(false);
    int n;
    cin >> n;

    for (int i = 0;i < n;i++) {
        int p, d;
        cin >> p >> d;
        //몇 일 (d)에 해당하는 p를 넣기        
        vec.push_back({ d, p });
    }

    //정렬을 수행
    sort(vec.begin(), vec.end());

    for (int i = 0;i < n;i++) {
        res += vec[i].second;
        pq.push(-vec[i].second); //음수로 넣기. 작은 놈이 앞에
        if (pq.size() > vec[i].first) {
            res += pq.top(); //빼주기
            pq.pop();
        }
    }

    cout << res << "\n";

    // while(!work.empty()) {
    //     auto cur = work.top(); work.pop();
    //     //같은 날짜일 때, 처리해줘야함. 하나만 선택하므로, 
    //     // cout<<"CONFIRM :  "<< cur.first<<" "<<cur.second<<" "<<endl;
    //     if(pastD == cur.first) continue;
    //     res+= cur.second;
    //     pastD = cur.first;
    // }

    // cout<<res<<"\n";
    return 0;
}