#include <iostream>
#include <stdio.h>
#include <cstring>
#include <queue>
using namespace std;

//variable
const int MAX = 101;
int cnt; //count 

int n, m; //input
int arr[MAX][MAX];
int visit[MAX][MAX];
int dirX[4] = { 0,0,1,-1};
int dirY[4] = { 1,-1,0,0 };

//isInside
bool isInside(int a, int b) {
	return (a < n && a >= 0) && (b < m && b>=0);
}

//bfs
int bfs() {

	int curX = 0; //current direction
	int curY = 0; //current direction
	queue<pair<int, int>> que; //pair : 한 쌍을 의미.
	que.push(pair<int, int>(curY, curX)); //Y, X 는 익숙한 좌표로 사용하기 위해서 바꿈.
	visit[curY][curX] = 1; //visit 한 것이므로, 1로 변경

	while (!que.empty()) {
		curY = que.front().first; //현재 node의 Y 좌표 값을 저장.
		curX = que.front().second; //현재 node의 X 좌표 값을 저장.
		que.pop(); //que POP 해줌.

		//다음은? 현재 curY, X에서 주위에 이웃한 node들을 탐색하는 과정. 
		//그 전에 확인할 것. isInside & 
		for (int i = 0; i < 4; i++) {
			int nextY = curY + dirY[i];
			int nextX = curX + dirX[i];

			if (isInside(nextY, nextX) && visit[nextY][nextX] == 0 && arr[nextY][nextX]) {
				visit[nextY][nextX] = visit[curY][curX] + 1;
				que.push(pair<int, int>(nextY, nextX));	
			}
		}
	}

	return visit[n - 1][m - 1];
}

//input
void input() {
	cin >> n >> m;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			scanf_s("%1d", &arr[i][j]);
		}
	}
}

//main
int main(void) {
	
	input();

	cout<<bfs();

	return 0;
}