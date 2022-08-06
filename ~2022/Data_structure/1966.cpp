#include <bits/stdc++.h>
using namespace std;

int main() {
    cin.tie(NULL); ios::sync_with_stdio(false);
    int t;
    cin >> t;
    while (t--) {
        vector<int> storeElement;
        deque<pair<int, int>> printQue;
        int res = 0; //결과로 출력할 변수
        int idx = 0;

        int n, m;; //문서의 갯수, 몇 번째로 인쇄되었는지 궁금한 문서
        cin >> n >> m;

        for (int i = 0;i < n;i++) {
            int temp;
            cin >> temp;
            storeElement.push_back(temp);
            printQue.push_back({ i,temp }); //앞이 idx, 뒤가 temp
        }

        while (!printQue.empty()) {
            //1. 현재 저장된 요소 중, 제일 큰 element를 체크
            sort(storeElement.begin(), storeElement.end());
            int maxElement = *max_element(storeElement.begin(), storeElement.end());

            //2. 맨 앞의 요소 체크
            pair<int, int> cur = printQue.front();

            //3. 이번에 나올 수 있는지 비교. maxelement와 비교 함 
            if (maxElement == cur.second) {
                idx++;

                //4. 찾는 idx인지 비교 -> 맞으면 res에 넣기
                if (cur.first == m) {
                    res = idx; //5. 세팅 후 출력
                    cout << res << "\n";
                }
                //storeElement에서 해당 idx를 pop                
                storeElement.pop_back();
                //내보낸다.
                printQue.pop_front();
            }
            else {
                //순서를 뒤로 넣어버림
                printQue.pop_front();
                printQue.push_back(cur);
            }
        }
    }
    return 0;
}