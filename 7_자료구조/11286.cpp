#include <bits/stdc++.h>
using namespace std;

int n; //100000
vector<int> vec;

struct compare
{
    bool operator()(int a, int b) {
        //a가 부모, b가 자식. a가 제일 작은 값이 있어야함
        if (abs(a) > abs(b)) {
            return true;
        }
        else if (abs(a) == abs(b)) {
            if (a > b) {

                return true;
            }
            else {
                return false;
            }
        }
        return false;
    }
};

int main() {
    cin.tie(NULL); ios::sync_with_stdio(false);
    // priority_queue<pair<int, int>> pq;
    priority_queue<int, vector<int>, compare> pq;

    cin >> n;
    for (int i = 0;i < n;i++) {
        int x;
        cin >> x;
        if (x == 0) { //가장 큰 값 출력 후, 제거
            if (!pq.empty()) {
                int cur = pq.top(); pq.pop();
                cout << cur << "\n";
            }
            else {
                cout << 0 << "\n";
            }
        }
        else { //배열에 넣기
            pq.push(x);
        }
    }

    return 0;
}