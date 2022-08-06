#include <bits/stdc++.h>
using namespace std;

string wb[8] = { "WBWBWBWB", "BWBWBWBW", "WBWBWBWB", "BWBWBWBW", "WBWBWBWB", "BWBWBWBW", "WBWBWBWB", "BWBWBWBW" };
string bw[8] = { "BWBWBWBW", "WBWBWBWB", "BWBWBWBW", "WBWBWBWB", "BWBWBWBW", "WBWBWBWB", "BWBWBWBW", "WBWBWBWB" };

int n, m;
int res = 987654321;
vector<string> vec;

int checkValue(int x, int y) {
    int wbval = 0; int bwval = 0;
    //1. wb 배열 체크
    for (int i = x;i < x + 8;i++) {
        for (int j = y;j < y + 8;j++) {
            if (vec[i][j] != wb[i - x][j - y]) wbval++; //이 범위 지정이 포인트
        }
    }
    //2. bw 배열 체크
    for (int i = x;i < x + 8;i++) {
        for (int j = y;j < y + 8;j++) {
            if (vec[i][j] != bw[i - x][j - y]) bwval++; //이게 포인트
        }
    }

    //3. 여기서도, 최솟값을 리턴 
    return min(bwval, wbval);
}

int main() {
    cin >> n >> m;
    for (int i = 0;i < n;i++) {
        string s; cin >> s;
        vec.push_back(s);
    }

    for (int i = 0;i <= n - 8;i++) {
        for (int j = 0;j <= m - 8;j++) {
            res = min(res, checkValue(i, j));
        }
    }

    cout << res << "\n";
    return 0;
}