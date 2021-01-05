#include <bits/stdc++.h>
using namespace std;

int board[50][50]; //input
int n, m;
vector<pair<int, int>> chicken;
vector<pair<int, int>> house;

int main() {
    cin >> n >> m;
    for (int i = 0;i < n;i++) {
        for (int j = 0;j < n;j++) {
            // 1 : house. 2 : chicken
            cin >> board[i][j];
            if (board[i][j] == 1) house.push_back({ i,j });
            if (board[i][j] == 2) chicken.push_back({ i,j });
        }
    }

    //0,1로 이루어진 next_permutation을 위한 Vector 생성
    vector <int> vec;
    for (int i = 0;i < chicken.size();i++) {
        if (i >= (chicken.size() - m)) vec.push_back(1);
        else vec.push_back(0);
    }

    int chickenDistance = 9999999;
    do
    {
        int curDistance = 0;
        for (int i = 0;i < house.size();i++) {
            //이미 선택된 치킨집들
            int temp = 9999999;
            for (int j = 0;j < chicken.size();j++) {
                if (vec[j] == 0) continue;
                temp = min(temp, abs(chicken[j].first - house[i].first) + abs(chicken[j].second - house[i].second));
            }
            curDistance += temp;
        }
        chickenDistance = min(curDistance, chickenDistance);
    } while (next_permutation(vec.begin(), vec.end()));

    //1. 최대 M개를 고르기 
    //2. 집에서 가까운 치킨집 찾기 => 찾을 필요 없이 chicken 벡터 접근하면 됨

    //3. 이번 loop의 total 값을 vec에 넣기
    cout << chickenDistance;
    return 0;
}