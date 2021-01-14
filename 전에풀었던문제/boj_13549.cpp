#include <iostream>
#include <queue>
#include <string.h>

using namespace std;
const int MAX = 1000000;

int n, m;
int visit[MAX]; //�湮�� ����ŭ ���� 
bool check[MAX]; //�湮�ߴ��� check

queue <int> main_que; //����ġ�� 0�� ť ó�� ������ ť
queue <int> next_que; 
int main(void) {

	cin >> n >> m;
	visit[n] = 0;
	check[n] = true;
	main_que.push(n);

	//main_que�� next_que�߿� ����ִ¾ָ� ã�ƾ���.
	while (!main_que.empty()) {
		int now = main_que.front();
		main_que.pop();

		//�� ���� ����
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
		//�̰� ��� �����س��� ��ü...?
		if (main_que.empty()) {
			main_que = next_que;
			next_que = queue<int>(); //���ο� ���� queue ����
		}
	}

	cout << visit[m]<<"\n";
	return 0;
}