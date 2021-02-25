#include <bits/stdc++.h>
using namespace std;

string endString = "123456780";
string start = "";
int dirX[4] = { 0,0,1,-1};
int dirY[4] = { 1,-1,0,0 };

bool isAvailable = false;
int res = 0;

set<string> chk;


int main() {
    ios::sync_with_stdio(false); cin.tie(NULL);
    //1. 입력을 String으로 받아온다.
    for (int i = 0;i < 3;i++) {
        for (int j = 0;j < 3;j++) {
            int input;
            cin >> input;
            start += to_string(input);
        }
    }

    //2. BFS 탐색. 
    //- String 자체를 탐색한 적이 있는지 확인하기 위해서 저장하는 set을 사용 
    queue<pair<string, int>> que; //문자열 자체랑, 카운트를 저장.
    que.push({start,0});
    chk.insert(start);

    while (!que.empty()) {
        auto cur = que.front(); que.pop();
        int zeroIdx = cur.first.find('0'); //0의 위치 
        int curX = zeroIdx / 3;
        int curY = zeroIdx % 3;

        if(cur.first == endString) {
            isAvailable = true;
            res = cur.second;
            break;
        }
        for (int i = 0;i < 4;i++) {
            int dx = curX + dirX[i];
            int dy = curY + dirY[i];
            if(dx >= 0 && dy >= 0 && dx < 3 && dy < 3) {
                string next = cur.first;
                swap(next[curX*3+curY],next[dx*3+dy]);

                if(chk.find(next) == chk.end()) {
                    chk.insert(next);
                    que.push({next,cur.second+1});
                }

            }
        }
    }
    if(isAvailable) {
        cout<<res<<"\n";
    }
    else {
        cout<<-1<<"\n";
    }
    return 0;
}