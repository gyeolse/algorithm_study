#include <iostream>
#include <queue>
#include <string.h>

using namespace std;
const int MAX = 1000000;

int n, m;
int visit[MAX]; //방문한 수만큼 증가 
bool check[MAX]; //방문했는지 check

queue <int> main_que; //가중치가 0인 큐 처음 시작인 큐
queue <int> next_que; 
int main(void) {

	cin >> n >> m;
	visit[n] = 0;
	check[n] = true;
	main_que.push(n);

	//main_que랑 next_que중에 비어있는애를 찾아야함.
	while (!main_que.empty()) {
		int now = main_que.front();
		main_que.pop();

		//세 가지 조건
		if (now * 2 < MAX) {
			if (check[now*2] == false) {
				main_que.push(now * 2);
				check[now * 2] = true;
				visit[now * 2] = visit[now];

			}
		}
		if (now - 1 >= 0) {
			if (check[now -1] == false) {
				next_que.push(now -1);
				check[now -1] = true;
				visit[now -1] = visit[now] + 1;
			}
		}
		if (now + 1 < MAX) {
			if (check[now + 1] == false) {
				next_que.push(now +1);
				check[now + 1] = true;
				visit[now + 1] = visit[now] + 1;
			}
		}
		//이걸 어떻게 생각해내냐 대체...?
		if (main_que.empty()) {
			main_que = next_que;
			next_que = queue<int>(); //새로운 다음 queue 생성
		}
	}

	cout << visit[m]<<"\n";
	return 0;
}