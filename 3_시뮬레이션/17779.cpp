#include <bits/stdc++.h>
using namespace std;
int n;
int arr[20][20];
int area[20][20];
pair<int, int> pos[4];

void input() {
    cin >> n;
    for (int i = 0;i < n;i++) {
        for (int j = 0;j < n;j++) {
            cin >> arr[i][j];
        }
    }
}

void print() {
    cout << endl;
    for (int i = 0;i < n;i++) {
        for (int j = 0;j < n;j++) {
            cout << arr[i][j] << " ";
        }
        cout << endl;
    }
}

bool isAvailable(int x, int y, int d1, int d2) {
    // 1번째 꼭지점
    if (x >= n || x < 0 || y >= n || y < 0) return false;
    // 2번째 꼭지점
    if (x + d1 >= n || x + d1 < 0 || y - d1 >= n || y - d1 < 0) return false;
    // 3번째 꼭지점
    if (x + d1 + d2 >= n || x + d1 + d2 < 0 || y - d1 + d2 >= n || y - d1 + d2 < 0) return false;
    // 4번째 꼭지점
    if (x + d2 >= n || x + d2 < 0 || y + d2 >= n || y + d2 < 0) return false;

    return true;
}

void splitArea(int x, int y, int d1, int d2) {
    memset(area, 0, sizeof(area));

    // 모든 부분을 5로 세팅    
    for (int i = 0;i < n;i++) {
        for (int j = 0;j < n;j++) {
            area[i][j] = 5;
        }
    }

    // 1번 선거구
    int subArea = 0;
    for (int i = 0;i < pos[1].second;i++) {
        if (i >= pos[0].second) subArea++;
        for (int j = 0;j < pos[0].second - subArea;j++) {
            area[i][j] = 1;
        }
    }

    // 2번 선거구 
    int plusArea = 0;
    for (int i = 0;i < pos[2].second;i++) {
        if (i > pos[0].second) plusArea++;

    }
}
int main() {
    input();



    for (int x = 0;x < n;x++) {
        for (int y = 0;y < n;y++) {
            for (int d1 = 0;d1 < n;d1++) {
                for (int d2 = 0;d2 < n;d2++) {
                    if (isAvailable(x, y, d1, d2)) {
                        pos[0].first = x; pos[0].second = y;
                        pos[1].first = x + d1; pos[1].second = y - d1;
                        pos[2].first = x + d2; pos[2].second = y + d2;
                        pos[3].first = x + d1 + d2; pos[3].second = y - d1 + d2;
                        splitArea(x, y, d1, d2);
                    }
                }
            }
        }
    }


    print();

    return 0;
}