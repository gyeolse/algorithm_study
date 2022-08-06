#include <bits/stdc++.h>
using namespace std;

//참고 : https://yabmoons.tistory.com/478

int main() {
    cin.tie(NULL); ios::sync_with_stdio(false);
    priority_queue<int> maxHeap;
    priority_queue<int> minHeap;

    int n;
    cin >> n;
    for (int i = 0;i < n;i++) {
        int t;
        cin >> t;

        if (maxHeap.size() > minHeap.size()) minHeap.push(-t);
        else maxHeap.push(t);

        if (!maxHeap.empty() && !minHeap.empty()) {
            if (maxHeap.top() > -minHeap.top()) {
                //swap
                int max_ = maxHeap.top();
                int min_ = -minHeap.top(); //ㅅㅂ
                maxHeap.pop(); minHeap.pop();
                maxHeap.push(min_); minHeap.push(-max_);
            }
        }
        cout << maxHeap.top() << "\n";
    }
    return 0;
}