//7576. 토마토
//ios::sync_with_stdio(false);

#include <cstdio>
#include <queue>
#include <iostream>
using namespace std;

//variable
//array
int arr[1000][1000]; //토마토가 있는가 없는가?
int d[1000][1000]; //
int n, m;

//direction
int dirY[] = {1,-1,0,0};
int dirX[] = { 0,0,1,-1 };

int main(void) {
//	ios::sync_with_stdio(false);

	//input
	cin >> m >> n;
	queue<pair<int, int>>q;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			cin >> arr[i][j];
			d[i][j] = -1; //방문을 안한 것으로 -1로 초기화를 모두 시켜줌. (그래야 해당 문제 조건 만족이 가능함)
			if (arr[i][j] == 1) { //만약 해당 위치에 토마토가 있다면 거기서부터 시작할 것.
				q.push(make_pair(i, j)); //queue에 push.
				d[i][j] = 0; //방문은 0으로 표시
			}
		}
	}

	//여기서 d배열이 어떤 역할을 하는지 알아두자. d 배열은 -1로 초기화 되어있고, 그 상태에서, arr배열이 1인 곳에서 시작하는 그 곳을
	//0으로 세팅함. 이유는 그 자리가 곧 시점이기 떄문임. 그 자리에 곧 익은 토마토가 위치한 곳이고, 거기서부터 옮겨가기 시작함.

	while (!q.empty()) {
		//큐에서 현재 원소 꺼내기
		int x = q.front().first;
		int y = q.front().second;
		q.pop();

		//해당 원소의 주변위치를 확인
		for (int i = 0; i < 4; i++) {
			int curX = x + dirX[i];
			int curY = y + dirY[i];
			//조건 check.
			if ((0 <= curX && curX < n) && (0 <= curY && curY < m)) { //안에 들어있니?
				if (arr[curX][curY] == 0 && d[curX][curY] == -1) { //arr 배열의 값이 0인데, 아직 방문하지 않았다. 라는 뜻임.
					d[curX][curY] = d[x][y] + 1; //현재 해당 위치 +  1 을 해줌. 
					q.push(make_pair(curX, curY)); //해당 인덱스를 다시 queue에 넣어줌.
				}
			}
		}
	}
	int answer = 0; 

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			if (answer < d[i][j]) {
				answer = d[i][j]; //answer은 배열내에서 제일 큰 값임.
			}
		}
	}

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			if (arr[i][j] == 0 && d[i][j] == -1) {
				answer = -1; //하나라도, 익지 않았는데 방문하지 못한 것이 있다면 answer은 -1
			}
		}
	}

	cout << answer << "\n";
	return 0;
}