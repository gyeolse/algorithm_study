#include <bits/stdc++.h>
using namespace std;

//1. 명령어 조합을 queue에 저장
//2. 톱니 배열을 deque에 저장

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    deque<int> topni[5];

    //input
    for (int i = 1;i < 5;i++) {
        string s;
        cin >> s;
        for (int j = 0;j < s.length();j++) {
            topni[i].push_back(s[j] - '0');
        }
    }

    int k;
    cin >> k;
    for (int i = 0;i < k;i++) {
        queue<pair<int, int>> cmd;
        int whois, dir;
        cin >> whois >> dir; // 3 -1

        int idx = whois; //대상 톱니바퀴로 설정
        int tempDir = dir; //목표의 방향
        cmd.push({ idx, tempDir }); //cmd에 대상, 방향을 넣음 (3, -1)

        //right
        while (1) {
            if (idx == 4) break;
            idx++;
            tempDir *= -1; //반대방향으로 설정

            if (topni[idx - 1][2] != topni[idx][6]) {
                cmd.push({ idx,tempDir });
            }
            else
            {
                break;
            }
        }

        idx = whois;
        tempDir = dir;

        //left
        while (1) {
            if (idx == 1) break;
            idx--;
            tempDir *= -1; //이딴 곳에서 틀리냐;
            if (topni[idx + 1][6] != topni[idx][2]) {
                cmd.push({ idx,tempDir });
            }
            else {
                break;
            }
        }

        //cmd 수행
        while (!cmd.empty()) {
            pair<int, int> cur = cmd.front(); cmd.pop();
            int curWho = cur.first;
            int curDir = cur.second;

            if (curDir == 1) { //1. 시계방향
                int temp = topni[curWho].back();
                topni[curWho].pop_back();
                topni[curWho].push_front(temp);
            }
            else { //2. 반시계방향
                int temp = topni[curWho].front();
                topni[curWho].pop_front();
                topni[curWho].push_back(temp);
            }
        }
    }

    int res = 0;

    for (int i = 1;i < 5;i++) {
        if (topni[i].front() == 1) {
            res += (int)pow(2, (i - 1));
        }
    }

    cout << res << "\n";
    return 0;
}