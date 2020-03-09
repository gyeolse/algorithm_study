//1697. 숨바꼭질

#include <iostream>
#include <queue>

using namespace std;
const int MAX = 200000;
int n, k;
int visit[MAX+1]; //visit 유무 확인
int dist[MAX+1]; //거리 측정
queue <int> que; //queue
/*
틀린 이유 : 기본적으로 bfs의 조건을 생각해보자. 
모든 vertex들을 한번씩만. 완전 탐색을 해야 한다는 것을 생각하자.
*/
int main(void) {
	cin >> n >> k;  //n=5, k=17
	visit[n] = 1;
	dist[n] = 0;
	que.push(n);
	//push해주자.
	while (!que.empty()) {
		//pop 해주고
		int cur = que.front();
		que.pop();

//cur-1, cur+1, 2*cur을 나누는 조건. 0<= X <=MAX 
		//cur-1 : cur-1 계속 하다보면 0보다 작은 순간이 오니까
		if (cur - 1 >= 0) { 
			if (visit[cur - 1] == 0) {
				que.push(cur - 1);
				visit[cur - 1] = 1;
				dist[cur - 1] = dist[cur] + 1;
			}
		}
		//cur+1 : MAX보다만 작으면 괜찮음 
		if (cur + 1 < MAX) {
			if (visit[cur + 1] == 0) {
				que.push(cur + 1);
				visit[cur + 1] = 1;
				dist[cur + 1] = dist[cur] + 1;
			}
		}

		//cur*2 : MAX보다만 작으면 괜찮음
		if (cur * 2 < MAX) {
			if (visit[cur * 2] == 0) {
				que.push(cur*2);
				visit[cur*2] = 1;
				dist[cur*2] = dist[cur] + 1;
			}
		}
	}
	cout << dist[k] << " ";
	return 0;
}
			/*
					//현재 위치에서 x-1, x+1, 2*x
					//조건1 : visit[cur-1],[cur+1][cur*2] == 0
					//조건2 : cur>=n && cur<k
					if (visit[cur - 1] == 0 && (cur-1)>=0) {
						//push 처리
						//visit 처리
						//visit 값 처리
						que.push(cur - 1);
						visit[cur - 1] = 1;
						dist[cur - 1] = dist[cur] + 1;

					}
					if (visit[cur + 1] == 0  && (cur+1) <= k) {
						que.push(cur + 1);
						visit[cur + 1] = 1;
						dist[cur + 1] = dist[cur] + 1;

					}
					if (visit[cur *2] == 0 && (cur*2) <= k) {
						que.push(cur *2);
						visit[cur *2] = 1;
						dist[cur *2] = dist[cur] + 1;
					}
					//3가지 경우의 수를 따져주고
					//해당 조건이 맞을 때, que에 다시 push
				}


				cout <<dist[k -1];

				내가 쓴 코드 : 틀린 이유를 모르겠음;
			*/
