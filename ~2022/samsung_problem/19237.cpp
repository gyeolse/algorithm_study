#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

struct Cell {
    vector<pair<int, int>> sharkArr;
    int nSmell;
    int kSec;
};

struct Priority {
    int one; int two; int three; int four;
};

// vector<Cell> cellArr(20); ///n,k

Cell cellArr[20][20];
vector<Priority> sharkPriority; // 차례대로 상어별 우선순위
int cnt = 0;
int n, m, k;
////////////////////////////////////////////////////////////////

// 1의 번호를 가진 상어가 있는지 확인 
bool isExistFirst(vector<pair<int, int>> sharkArr) {
    bool val;
    for (int i = 0;i < sharkArr.size();i++) {
        if (sharkArr[i].first == 1) return true;
    }
    return false;
}

bool checkLoop() {
    bool isAvailable = true;
    for (int i = 0;i < n;i++) {
        for (int j = 0;j < n;j++) {
            if (cellArr[i][j].sharkArr.size() != 0) {
                if (cellArr[i][j].nSmell != 1) return true;
            }
        }
    }
    return false;
}

// 냄새빼기 
void subtractSmell() {
    // array 돌면서, 
    for (int i = 0;i < n;i++) {
        for (int j = 0;j < n;j++) {
            if (cellArr[i][j].nSmell != 0) {
                cellArr[i][j].kSec--; // 상어 array 는 손대면 안돼 
            }
        }
    }
}

// 상어 움직이기 처리하기 
void moveShark() {
    
}

// 자리 이동 확인 

// 1-1. 맨처음에 상어가 자기가 있는 자리에 냄새뿌리는거 처리하기     

// 이동방향 결정 함수 (범위체크 필수)
// 0) 인접한 칸 중 아무냄새가 없는 칸 비어있는 방향. -> 우선순위에 따름
// 1) 자신의 냄새가 있는 칸의 방향
// 1-1) 만약 여러 곳일 경우, 특정 우선순위에 따르기 
// 1-2) 여러곳 확인 -> cnt 

// 여러 상어 있는지 체크 함수
// 여러마리가 있는 경우, 1에 해당하는 상어가 있는지 체크 로직 
// 그게 아니라면, 가장 작은 번호만 두고 나머지 pop

int main() {
    // input 
    cin >> n >> m >> k;

    // 맨처음에 넣을 때, 같이 넣으면 되겠네
    for (int i = 0;i < n;i++) {
        for (int j = 0;j < n;j++) {
            int tmp; cin >> tmp;
            Cell cell;
            if (tmp == 0) {
                cell.kSec = 0; cell.nSmell = 0;
            }
            else {
                cell.kSec = k;
                cell.nSmell = tmp; // n이 누군지
                cell.sharkArr.push_back({ tmp, k }); // 상어 쳐넣기
            }
            cellArr[i][j] = cell;
        }
    }

    while (1) {
        // 0. OK 1초에 한번씩

        // 0. 냄새 k -1 씩 빼기 처리하기
        subtractSmell();

        // 상어 이동시키기
        moveShark();

        // 한칸에 여러 상어가 있는지 체크하고, 한 놈만 남기기
    
        // 상어가 있는 자리에 냄새 뿌리기 


        if (checkLoop() == false) break;
        cnt++;
    }

    cout << cnt << "\n";
    return 0;
}