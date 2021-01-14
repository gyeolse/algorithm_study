//14226. 이모티콘

#include <iostream>
#include <string.h>
#include <queue>
#include <tuple> //tie 함수

using namespace std;

/*	
	1. 저장 (s,c) -> (s,s)
	2. 붙여넣기 (s,c) -> (s+c,c)
	3. 삭제 (s,c) -> (s-1,c)
*/

int check[999][999]; //가는데 얼만큼 걸렸는지.
queue <pair<int, int>> que; 
int n;


int main(void) {
	ios::sync_with_stdio(false);
//	memset(check, 0, sizeof(check));
	memset(check, -1, sizeof(check));

	cin >> n;

	//화면에 1, 클립보드에 0
	que.push(make_pair(1, 0));
	check[1][0] = 0; //-1 -> -1+1 = 0 한번 방문 +1초

	while (!que.empty()) {
		//3가지 경우
		int s, c;
		tie(s, c) = que.front(); //que에서 묶는 역할, //tuple 생성
		que.pop();

		//조건1. check[s][s] == -1 일 떄. 저장. 아직 방문X
		if (check[s][s] == -1) {
			check[s][s] = check[s][c] + 1;
			que.push(make_pair(s, s)); //s,s일때의 모든 경우 확인위해서 push.
		}
		//조건2. check[s+c][c] ==-1일 때. 붙여넣기
		if (s + c <= n && check[s + c][c] == -1) {
			check[s + c][c] = check[s][c] + 1;
			que.push(make_pair(s + c, c));
		}

 		//조건3. check[s-1][c] == -1일 때. 삭제
		if (s - 1 >= 0 && check[s - 1][c] == -1) {
			check[s - 1][c] = check[s][c] + 1;
			que.push(make_pair(s - 1, c));
		}	
	}

	int answer = -1;

	//체크. 총 n개의 이모티콘.
	for (int i = 0; i <= n; i++) {
		//check[n][i]가 -1이 아닌경우, 그 중에서.
		if (check[n][i] != -1) {
			//answer가 check의 값보다 크거나, -1이면.
			if (answer == -1 || answer > check[n][i]) {
				answer = check[n][i];
			}
		}
	}

	cout <<answer<<"\n";
	return 0;
}