#include <bits/stdc++.h>
using namespace std;
int resR, resC, k;
int board[101][101];
int time_ = 0;

int indexR = 3;
int indexC = 3;
int numCount[101];

void input() {
    cin >> resR >> resC >> k; //r,c의 위치가 k가 되는지를 확인
    for (int i = 1;i <= 3;i++) {
        for (int j = 1;j <= 3;j++) {
            cin >> board[i][j];
        }
    }
}

void output() {
    //조건 만족하는지 확인 후, 맞으면 time, 만족 못하면 -1
    if (board[resR][resC] == k) {
        cout << time_ << "\n";
    }
    else {
        cout << -1 << "\n";
    }
}

void print() {
    cout << endl;
    for (int i = 1;i <= indexR;i++) {
        for (int j = 1;j <= indexC;j++) {
            cout << board[i][j] << " ";
        }
        cout << endl;
    }
}

void solution() {

    while (1) {
        if (board[resR][resC] == k) break; //조건 부합하면 탈출
        if (time_ > 100) break; //100초를 넘어가면 탈출

        // indexR 과 indexC를 비교
        vector<int> sz;

        // R == 행, C == 열
        if (indexR >= indexC) {
            for (int i = 1;i <= indexR;i++) {
                vector<pair<int, int>> vec;
                memset(numCount, 0, sizeof(numCount));

                for (int j = 1;j <= indexC;j++) {
                    numCount[board[i][j]]++;
                }

                for (int j = 1;j <= 100;j++) {
                    if (numCount[j] == 0) continue;
                    // vec에 넣기 
                    vec.push_back({ numCount[j],j });
                }

                sort(vec.begin(), vec.end());
                // vec의 크기 만큼 board 새로 고침하고, indexR 값 새로고침 
                for (int j = 1;j <= indexC;j++) {
                    board[i][j] = 0;
                }

                int idx = 1;
                for (int j = 0;j < vec.size();j++) {
                    board[i][idx++] = vec[j].second;
                    board[i][idx++] = vec[j].first;
                }
                idx--;
                sz.push_back(idx);
            }

            indexC = *max_element(sz.begin(),sz.end());
            // sort(sz.begin(), sz.end());
            // indexC = sz.back();
        }
        else {
            for (int i = 1;i <= indexC;i++) {
                vector<pair<int, int>> vec;

                memset(numCount, 0, sizeof(numCount));
                for (int j = 1;j <= indexR;j++) {
                    numCount[board[j][i]]++;
                }

                for (int j = 1;j <= 100;j++) {
                    if (numCount[j] == 0) continue;
                    // vec에 넣기 
                    vec.push_back({ numCount[j],j });
                }

                sort(vec.begin(), vec.end());
                // vec의 크기 만큼 board 새로 고침하고, indexR 값 새로고침 
                for (int j = 1;j <= indexR;j++) {
                    board[j][i] = 0;
                }

                int idx = 1;
                for (int j = 0;j < vec.size();j++) {
                    board[idx++][i] = vec[j].second;
                    board[idx++][i] = vec[j].first;
                }
                idx--;
                sz.push_back(idx);
            }
            indexR = *max_element(sz.begin(),sz.end());
            // sort(sz.begin(), sz.end());
            // indexR = sz.back();
        }
        time_++;
    }
}

int main() {

    // 입력
    input();

    if(board[resR][resC] == k ) {
        cout<<0<<endl;
        return 0;
    }

    // Solution 
    solution();

    // 값 확인 
    // print();

    // 출력
    output();
}