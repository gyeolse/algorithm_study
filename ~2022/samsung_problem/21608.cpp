#include <bits/stdc++.h>
using namespace std;
#define MAX 25

struct STUDENT {
    int Num;
    int Friend[4];
};

struct POSITION {
    int x; int y; int Nearly_Empty; int Nearly_Friend;
};

STUDENT studentArr[MAX * MAX];
vector<STUDENT> Student;
int n;
int MAP[MAX][MAX];
int dirX[4] = { 0,1,0,-1 };
int dirY[4] = { 1,0,-1,0 };
int ans;

int cal(int f) {
    if (f == 0) return 0;
    if (f == 1) return 1;
    if (f == 2) return 10;
    if (f == 3) return 100;
    if (f == 4) return 1000;
    return -1;
}

void satisfy() {
    for (int i = 0;i < n;i++) {
        for (int j = 0;j < n;j++) {
            int studentNum = MAP[i][j];
            int Friend = 0;
            for (int k = 0;k < 4;k++) {
                int nx = i + dirX[k];
                int ny = j + dirY[k];
                if (nx >= n || ny >= n || nx < 0 || ny < 0) continue;

                for (int l = 0;l < 4;l++) {
                    int friendNum = studentArr[studentNum].Friend[l];
                    if (MAP[nx][ny] == friendNum) {
                        Friend++;
                    }
                }
            }

            ans += cal(Friend);
        }
    }
}

// 비어있는 칸 중에서 좋아하는 학생이 인접한 칸에 가장 많은 칸으로 자리를 정한다.
// 1을 만족하는 칸이 여러 개이면, 인접한 칸 중에서 비어있는 칸이 가장 많은 칸으로 자리를 정한다.
// 2를 만족하는 칸도 여러 개인 경우에는 행의 번호가 가장 작은 칸으로, 그러한 칸도 여러 개이면 열의 번호가 가장 작은 칸으로 자리를 정한다.

bool Cmp(POSITION A, POSITION B) {
    if (A.Nearly_Friend >= B.Nearly_Friend) {
        if (A.Nearly_Friend == B.Nearly_Friend) {
            if (A.Nearly_Empty >= B.Nearly_Empty) {
                if (A.Nearly_Empty == B.Nearly_Empty) {
                    if (A.x <= B.x) {
                        if (A.x == B.x) {
                            if (A.y < B.y) {
                                return true;
                            }
                            return false;
                        }
                        return true;
                    }
                    return false;
                }
                return true;
            }
            return false;
        }
        return true;
    }
    return false;
}

void setPosition() {
    // 순서대로 자리를 배치해줘야 한다....
    for (int i = 0;i < Student.size();i++) {
        vector<POSITION> pos;
        int Student_Num = Student[i].Num; // 학생 번호

        // 맵을 돌면서
        for (int x = 0; x < n; x++) {
            for (int y = 0; y < n;y++) {
                if (MAP[x][y] != 0) continue; // ? 

                int Nearly_Friend = 0;
                int Nearly_Empty = 0;

                for (int k = 0;k < 4;k++) {
                    int dx = x + dirX[k];
                    int dy = y + dirY[k];
                    if (dx < 0 || dx >= n || dy < 0 || dy >= n) continue;
                    if (MAP[dx][dy] == 0) Nearly_Empty++;
                    else {
                        for (int j = 0;j < 4;j++) {
                            int friendNum = Student[i].Friend[j]; // 해당 친구 번호
                            if (MAP[dx][dy] == friendNum) {
                                Nearly_Friend++;
                                break;
                            }
                        }
                    }
                }
                pos.push_back({ x,y,Nearly_Empty, Nearly_Friend });
            }
        }
        sort(pos.begin(), pos.end(), Cmp);
        int pos_x = pos[0].x;
        int pos_y = pos[0].y;
        MAP[pos_x][pos_y] = Student_Num;
    }
}


int main() {
    cin >> n;
    for (int i = 0;i < n * n;i++) {
        int a, b, c, d, e;
        cin >> a >> b >> c >> d >> e;
        Student.push_back({ a, {b,c,d,e} });
        studentArr[a].Num = a;
        studentArr[a].Friend[0] = b;
        studentArr[a].Friend[1] = c;
        studentArr[a].Friend[2] = d;
        studentArr[a].Friend[3] = e;
    }

    setPosition();
    satisfy();
    cout << ans << endl;

    return 0;
}