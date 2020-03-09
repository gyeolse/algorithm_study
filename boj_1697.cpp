//1697. ���ٲ���

#include <iostream>
#include <queue>

using namespace std;
const int MAX = 200000;
int n, k;
int visit[MAX+1]; //visit ���� Ȯ��
int dist[MAX+1]; //�Ÿ� ����
queue <int> que; //queue
/*
Ʋ�� ���� : �⺻������ bfs�� ������ �����غ���. 
��� vertex���� �ѹ�����. ���� Ž���� �ؾ� �Ѵٴ� ���� ��������.
*/
int main(void) {
	cin >> n >> k;  //n=5, k=17
	visit[n] = 1;
	dist[n] = 0;
	que.push(n);
	//push������.
	while (!que.empty()) {
		//pop ���ְ�
		int cur = que.front();
		que.pop();

//cur-1, cur+1, 2*cur�� ������ ����. 0<= X <=MAX 
		//cur-1 : cur-1 ��� �ϴٺ��� 0���� ���� ������ ���ϱ�
		if (cur - 1 >= 0) { 
			if (visit[cur - 1] == 0) {
				que.push(cur - 1);
				visit[cur - 1] = 1;
				dist[cur - 1] = dist[cur] + 1;
			}
		}
		//cur+1 : MAX���ٸ� ������ ������ 
		if (cur + 1 < MAX) {
			if (visit[cur + 1] == 0) {
				que.push(cur + 1);
				visit[cur + 1] = 1;
				dist[cur + 1] = dist[cur] + 1;
			}
		}

		//cur*2 : MAX���ٸ� ������ ������
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
					//���� ��ġ���� x-1, x+1, 2*x
					//����1 : visit[cur-1],[cur+1][cur*2] == 0
					//����2 : cur>=n && cur<k
					if (visit[cur - 1] == 0 && (cur-1)>=0) {
						//push ó��
						//visit ó��
						//visit �� ó��
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
					//3���� ����� ���� �����ְ�
					//�ش� ������ ���� ��, que�� �ٽ� push
				}


				cout <<dist[k -1];

				���� �� �ڵ� : Ʋ�� ������ �𸣰���;
			*/
