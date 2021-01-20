#include <bits/stdc++.h>
using namespace std;

int n; //100000

int main() {
    cin.tie(NULL); ios::sync_with_stdio(false);
    priority_queue<int> pq;
    cin >> n;
    for (int i = 0;i < n;i++) {
        int x;
        cin >> x;
        if (x == 0) { //가장 큰 값 출력 후, 제거
            if (!pq.empty()) {
                int min_ = -pq.top(); pq.pop();
                cout << min_ << "\n";
            }
            else {
                cout << 0 << "\n";
            }
        }
        else { //배열에 넣기
            pq.push(-x);
        }
    }

    return 0;
}