#include <bits/stdc++.h>
using namespace std;

deque<int> topni[5]; //행은 가변이지만 열은 4로 고정시킴
// int d; //방향 (시계/반시계)

int main() {
    for (int i = 1;i < 5;i++) {
        string s;
        cin >> s;
        for (int j = 0;j < s.size();j++) {
            topni[i].push_back(s[j] - '0');
        }
    }

    int k; //회전 횟수
    cin >> k;

    for (int i = 0;i < k;i++) {
        queue<pair<int, int>> que; //명령어 넣기
        int topni_num, direction;
        cin >> topni_num >> direction;

        //1. 오른쪽 방향 체크 
        int idx = topni_num; // 틀
        int tempDirection = direction;
        que.push({ idx,tempDirection });
        while (1) {
            if (idx == 4) break;
            idx++;
            tempDirection *= -1;
            if (topni[idx - 1][2] != topni[idx][6]) {
                que.push({ idx, tempDirection });
            }
            else { //else 분기처리 틀림
                break;
            }
        }

        //2. 왼쪽 방향 체크 
        idx = topni_num;
        tempDirection = direction;
        while (1) {
            if (idx == 1) break;
            idx--;
            tempDirection *= -1;
            if (topni[idx + 1][6] != topni[idx][2]) {
                que.push({ idx,tempDirection });
            }
            else {
                break;
            }
        }

        //3. 실제 연산을 수행
        while (!que.empty()) {
            int curTopni = que.front().first;
            int curDirection = que.front().second;
            que.pop();

            //(front)====(back)
//시계방향과 반시계방향의 순서를 바꾸면 답이 다르게 나온다...가 아니라,
//반시계방향일때를 0으로 써서 틀린거였다.... 바본가
            if (curDirection == 1) {  //시계방향
                //10101111 -> 11010111
                int temp = topni[curTopni].back();
                topni[curTopni].pop_back();
                topni[curTopni].push_front(temp);
            }
            else {
                //10101111 -> 01011110
                int temp = topni[curTopni].front(); //
                topni[curTopni].pop_front();
                topni[curTopni].push_back(temp);
            }
        }
    }

    //결과 출력
    int res = 0;
    for (int i = 1;i < 5;i++) {
        if (topni[i][0] == 1) {
            res += (int)pow(2, (i - 1));
        }
    }

    cout << res << "\n";
    return 0;
}