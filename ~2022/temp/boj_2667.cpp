#include <iostream>
#include <algorithm>
#include <cstdio>

using namespace std;

int map[25][25]; //지도
int arrSize[323]; //크기가 n일때 집의 최대 갯수
int dir[4][2] = { {-1,0},{1,0},{0,-1},{0,1} }; //상하좌우 확인을 위한 2차원 배열
int cnt; //단지의 개수
int n; //입력받을 n

//true일 경우에만, return true. 0보다 작다거나, n이 a보다 큰 경우는 return false
bool isInside(int a, int b) {
	return (a >= 0 && a < n) && (b >= 0 && b < n);
}

void dfs(int a, int b, int key) {
	map[a][b] = key; //key는 단지의 number값을 말함
	//단지번호로 map의 값을 reset시킴
	for (int i = 0; i < 4; i++) { //x,y 방향에 맞춰서 완전탐색
		int dy = a + dir[i][0]; //y 
		int dx = b + dir[i][1]; //x 

		if (isInside(dy, dx) && map[dy][dx] == 1) { //범위내에 존재하는 index에 1이 있을 경우
			dfs(dy, dx, key); //재귀. dfs 시작.
		}
	}
}

void Solution(int n) {
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			if (map[i][j] == 1) {
				cnt++; //단지 번호 ++ 해주기 
				dfs(i, j, cnt + 1); //1일 경우, 그 곳에서부터 dfs 시작
			}
		}
	}

	for (int i = 0; i < n; i++) { //각 dfs마다 숫자 지정해둠.
		for (int j = 0; j < n; j++) {
			//map[i][j]>2일때부터. 2-2=0, 3-2=1, 4-2=2....
			//--- arrSize[0],[1],[2]에 ++하는 과정.  
			if (map[i][j] > 1) { 
				arrSize[map[i][j] - 2]++;
			}
		}
	}
}

int main(void) {
	cin >> n;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			scanf_s("%1d", &map[i][j]);
		}
	}
	Solution(n);
	sort(arrSize, arrSize + cnt); //정렬 (오름차순)
	cout << cnt << endl;
	for (int i = 0; i < cnt; i++) {
		cout << arrSize[i] << endl;
	}

	return 0;
}