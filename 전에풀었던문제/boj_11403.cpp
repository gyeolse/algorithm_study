#include <iostream>
#include <cstring>

using namespace std;

int arr[101][101]; //input 배열.
int result[101][101]; //output 배열
bool visit[101][101]; //방문 확인

int n; //vertex의 개수

void dfs(int fix, int x, int y) {
	visit[fix][y] = true;
	result[fix][y] = 1;

	for (int i = 0; i < n; i++) {
		if (arr[y][i] == 1 && visit[fix][i] == false) {
			dfs(fix,y, i);
		}
	}
}

int main(void) {

	memset(arr, 0, sizeof(arr));
	memset(result, 0, sizeof(result));
	memset(visit, false, sizeof(visit));

	//집어넣기
	cin >> n;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			cin >> arr[i][j];
		}
	}

	//dfs
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			if(visit[i][j]==false && arr[i][j]==1)
				dfs(i, i, j);
		}
	}

	//output
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			cout << result[i][j] << " ";
		}
		cout << "\n";
	}
}

