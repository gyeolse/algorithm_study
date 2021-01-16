#include <bits/stdc++.h>
using namespace std;

int board1[100][100];
int board2[100][100];
int n, l;

bool makeRoadAvailable(int arr[][100], int x, int y) {
    int standard = arr[x][y + 1]; //뒤에 계속 놓을 수 있는지를 확인해야함.
    for (int j = y + 1;j < y + 1 + l;j++) {
        if (arr[x][j] != standard) return false;
    }
    return true;
}

int main() {
    //1. 입력 받는다.
    cin>>n>>l;
    for (int i = 0;i < n;i++) {
        for (int j = 0;j < n;j++) {
            cin >> board1[i][j];
            //2. 전치. board2에 넣는다.
            board2[j][i] = board1[i][j];
        }
    }

    //3. 길 순회
    int totalRoad = 0;

    int board_road_1 = 0;
    int board_road_2 = 0;

    for (int i = 0;i < n;i++) {
        bool can_road = true; //?
        int before_road = 1; //전에 도로가 몇 개인지

        for (int j = 0;j < n - 1;j++) {
            if (board1[i][j] == board1[i][j + 1]) before_road++; //첫 번쨰. 같을 때.
            else if (board1[i][j] == board1[i][j + 1] + 1) { //두 번째. 앞의 것이 더 클 때
                if (makeRoadAvailable(board1, i, j) == true) { //경사로 만들 수 있는지
                    j = j + l - 1; //경사로 세팅. (그 뒤로 넘어감)
                    before_road = 0;
                }
                else { //불가능. 해당 loop 탈출
                    can_road = false;
                    break;
                }
            }
            else if (board1[i][j] + 1 == board1[i][j + 1]) { //세 번쨰. 뒤의 것이 더 클 때
                if (before_road >= l) {
                    before_road = 1;
                }
                else {
                    can_road = false;
                    break;
                }
            }
            else if (abs(board1[i][j] - board1[i][j + 1]) >= 2) {
                can_road = false;
                break;
            }
        }

        if (can_road == true) {
            board_road_1++;
        }
    }

    totalRoad += board_road_1;
    

    for (int i = 0;i < n;i++) {
        bool can_road = true; //?
        int before_road = 1; //전에 도로가 몇 개인지

        for (int j = 0;j < n - 1;j++) {
            if (board2[i][j] == board2[i][j + 1]) before_road++; //첫 번쨰. 같을 때.
            else if (board2[i][j] == board2[i][j + 1] + 1) { //두 번째. 앞의 것이 더 클 때
                if (makeRoadAvailable(board2, i, j) == true) { //경사로 만들 수 있는지
                    j = j + l - 1; //경사로 세팅. (그 뒤로 넘어감)
                    before_road = 0;
                }
                else { //불가능. 해당 loop 탈출
                    can_road = false;
                    break;
                }
            }
            else if (board2[i][j] + 1 == board2[i][j + 1]) { //세 번쨰. 뒤의 것이 더 클 때
                if (before_road >= l) {
                    before_road = 1;
                }
                else {
                    can_road = false;
                    break;
                }
            }
            else if (abs(board2[i][j] - board2[i][j + 1]) >= 2) {
                can_road = false;
                break;
            }
        }

        if (can_road == true) {
            board_road_2++;
        }
    }


    totalRoad += board_road_2;

    cout << totalRoad << "\n";
    return 0;
}