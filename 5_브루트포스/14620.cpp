//https://hibee.tistory.com/70 나중에 참고할 블로그 

#include <bits/stdc++.h>
using namespace std;

int n; //한 변의 길이
int priceList[15][15]; //가격 리스트 
vector<pair<int, int>> location; //좌표 저장

int dirX[4] = { 1,0,-1,0 };
int dirY[4] = { 0,1,0,-1 };

int res = 987654321;

int chk[15][15]; 

bool isAvailable(int x,int y) {
    if(x < 0 || y < 0 || x > n-1 || y > n-1) {
        return false;
    }
    return true;
}
int main() {
    cin >> n;
    for (int i = 0;i < n;i++) {
        for (int j = 0;j < n;j++) {
            cin >> priceList[i][j];
            location.push_back({ i,j });
        }
    }

    vector<int> forLoop;
    for (int i = 0;i < (n * n) - 3;i++) {
        forLoop.push_back(0);
    }

    for (int i = 0;i < 3;i++) {
        forLoop.push_back(1);
    }

    do
    {
        vector<pair<int, int>> flowerLocation; //꽃 위치 

        //꽃 위치 세팅
        for(int i=0;i<forLoop.size();i++) {
            if(forLoop[i] == 1) {
                flowerLocation.push_back(location[i]);                
            }
        }

        //꽃의 위치 적합 부적합 판단, 
        memset(chk,0,sizeof(chk));
        int cnt = 0;
        int curCost = 0;
        for(int i=0;i<flowerLocation.size();i++) {
            cnt++;
            auto cur = flowerLocation[i];
            
            chk[cur.first][cur.second] = 1;
            curCost += priceList[cur.first][cur.second];
            //네 방향 탐색 및, 현재 위치 설정
            for(int dir = 0; dir<4; dir++) {
                int curX = cur.first + dirX[dir];
                int curY = cur.second + dirY[dir];
                if(isAvailable(curX,curY)) {
                    if(chk[curX][curY] != 1 ) {
                        curCost += priceList[curX][curY];
                        chk[curX][curY] = 1;
                        cnt++;
                    }
                    else {
                        break;
                    }
                } 
                else {
                    break;
                }
            }
        }

        if(cnt==15) {
            res = min(curCost,res);
        }

        //cnt가 4이면, min 값을 저장
    } while (next_permutation(forLoop.begin(),forLoop.end()));

    cout<<res<<"\n";

    return 0;
}