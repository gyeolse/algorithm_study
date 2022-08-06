#include <bits/stdc++.h>
using namespace std;

int solution(vector<int> priorities, int location) {    
    int answer = 0; 
    deque<pair<int,int>> que; //순위, idx
    priority_queue<int> pq;
    
    for(int i=0;i<priorities.size();i++) {
        que.push_back({priorities[i],i}); //뒤로 넣고
        pq.push(priorities[i]);
    }    
    cout<<pq.top()<<endl;
    int cnt = 0;

    while(!que.empty()) {
        auto cur = que.front(); que.pop_front(); //앞에서 빼고, pop        
        cout<<cur.first<<" "<<cur.second<<endl;

        //현재 수랑이랑, priorities 맨 앞이랑 비교
        if(cur.first < pq.top()) { //현재가 max 보다 더 작다면
            que.push_back(cur); //다시 뒤로 넣기
        }
        else { //현재 크거나 같다면
            // cout<<"나가는 놈 Idx랑 몇번쨰? "<<cur.second<<" "<<cnt<<endl;
            pq.pop(); //1회 pop
            
            if(cur.second == location ) {
                answer = cnt;
            }
            cnt++;
        }
    }
    
    return answer;
}

int main() {
    vector<int> a = {1,1,9,1,1,1};
    int loc = 0;
    cout<<solution(a,0)<<endl;
    return 0;
}