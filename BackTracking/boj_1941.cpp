#include <iostream>
#include <queue>
#include <string>
#include <cstring>

using namespace std;

int ans;
int dirX[4] = { 0,0,1,-1};
int dirY[4] = { 1,-1,0,0 };
bool Select[25];
int MAP[5][5];

bool MoreThanFour() {
	//7일때만 호출이 됨.
	int cnt = 0;
	for (int i = 0; i < 25; i++) {
		if (Select[i] == true) {
			int x = i / 5;
			int y = i % 5;
			if (MAP[x][y] == 2) cnt++;
		}
	}
	if (cnt >= 4) return true;
	else return false;
}

bool Adjacency() {
	//7일때만 호출이 됨.
	queue<pair<int, int>> que;
	bool check_select[5][5];
	bool queue_select[5][5];
	bool check_ans = false;
	memset(check_select, false, sizeof(check_select));
	memset(queue_select, false, sizeof(queue_select));
	
	int temp = 0;
	for (int i = 0; i < 25; i++) {
		if (Select[i] == true) {
			int x = i / 5;
			int y = i % 5;
			check_select[x][y] = true;
			if (temp == 0) {
				que.push({ x,y });
				queue_select[x][y] = true;
				temp++; //맨 처음만 실행되는 코드
			}
		}
	}

	int cnt = 1;
	while (!que.empty()) {
		pair<int, int> cur = que.front(); que.pop();
		if (cnt == 7) {
			check_ans = true;
			break;
		}

		for (int i = 0; i < 4; i++) {
			int curX = cur.first + dirX[i];
			int curY = cur.second + dirY[i];
			if (curX < 0 || curY < 0 || curX>4 || curY>4) continue;
			if (check_select[curX][curY] == false || queue_select[curX][curY] == true) continue;
			queue_select[curX][curY] = true;
			que.push({ curX,curY });
			cnt++;
		}
	}

	if (check_ans == true) return true;
	return false;
}

void dfs(int idx, int cnt) {
	if (cnt == 7) {
		if (MoreThanFour() == true) {
			if (Adjacency() == true) {
				ans++;
			}
		}
		return;
	}

	for (int i = idx; i < 25; i++) { //순열이니까
		if (Select[i] == true) continue;
		Select[i] = true;
		dfs(i, cnt + 1);
		Select[i] = false;
	}
}

int main(void) {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	for (int i = 0; i < 5; i++) {
		string input;
		cin >> input;
		for (int j = 0; j < input.length(); j++) {
			if (input[j] == 'Y') MAP[i][j] = 1;
			else if (input[j] == 'S') MAP[i][j] = 2;
		}
	}
	dfs(0, 0);
	cout << ans << "\n";
	return 0;
}
