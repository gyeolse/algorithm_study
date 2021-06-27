#include <bits/stdc++.h>
using namespace std;

vector<int> solution(vector<int> prices) {
    vector<int> answer;

    queue<pair<int, pair<int, int>>> que; //idx, price, time 저장
    int t_ = prices.size();
    for (int i = 0;i < t_;i++) {
        //idx : idx+1 저장, prcies는 해당 idx 값, time은 t_-(idx+1)
        int idx = i + 1;
        int price = prices[i];
        int curTime = t_ - (idx);
        // cout<<idx<<" "<<price<<" "<<curTime<<endl;
        que.push({ idx,{price,curTime} });
    }

    while (!que.empty()) {
        auto cur = que.front(); que.pop();
        int curIdx = cur.first; //3
        int curPrice = cur.second.first; //3
        int curTime = cur.second.second; //2
        // t_ = total_time
        for (int i = (curIdx - 1);i < prices.size();i++) {
            if (curPrice > prices[i]) {  //가격이 작아진 순간에
                curTime = (i + 1) - curIdx;
                // cout<<curIdx<<curPrice<<curTime<<" 확인"<<endl;
                break;
            }
        }
        answer.push_back(curTime);
    }

    return answer;
}