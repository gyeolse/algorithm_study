//14226. �̸�Ƽ��

#include <iostream>
#include <string.h>
#include <queue>
#include <tuple> //tie �Լ�

using namespace std;

/*	
	1. ���� (s,c) -> (s,s)
	2. �ٿ��ֱ� (s,c) -> (s+c,c)
	3. ���� (s,c) -> (s-1,c)
*/

int check[999][999]; //���µ� ��ŭ �ɷȴ���.
queue <pair<int, int>> que; 
int n;


int main(void) {
	ios::sync_with_stdio(false);
//	memset(check, 0, sizeof(check));
	memset(check, -1, sizeof(check));

	cin >> n;

	//ȭ�鿡 1, Ŭ�����忡 0
	que.push(make_pair(1, 0));
	check[1][0] = 0; //-1 -> -1+1 = 0 �ѹ� �湮 +1��

	while (!que.empty()) {
		//3���� ���
		int s, c;
		tie(s, c) = que.front(); //que���� ���� ����, //tuple ����
		que.pop();

		//����1. check[s][s] == -1 �� ��. ����. ���� �湮X
		if (check[s][s] == -1) {
			check[s][s] = check[s][c] + 1;
			que.push(make_pair(s, s)); //s,s�϶��� ��� ��� Ȯ�����ؼ� push.
		}
		//����2. check[s+c][c] ==-1�� ��. �ٿ��ֱ�
		if (s + c <= n && check[s + c][c] == -1) {
			check[s + c][c] = check[s][c] + 1;
			que.push(make_pair(s + c, c));
		}

 		//����3. check[s-1][c] == -1�� ��. ����
		if (s - 1 >= 0 && check[s - 1][c] == -1) {
			check[s - 1][c] = check[s][c] + 1;
			que.push(make_pair(s - 1, c));
		}	
	}

	int answer = -1;

	//üũ. �� n���� �̸�Ƽ��.
	for (int i = 0; i <= n; i++) {
		//check[n][i]�� -1�� �ƴѰ��, �� �߿���.
		if (check[n][i] != -1) {
			//answer�� check�� ������ ũ�ų�, -1�̸�.
			if (answer == -1 || answer > check[n][i]) {
				answer = check[n][i];
			}
		}
	}

	cout <<answer<<"\n";
	return 0;
}