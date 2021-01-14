//7576. �丶��
//ios::sync_with_stdio(false);

#include <cstdio>
#include <queue>
#include <iostream>
using namespace std;

//variable
//array
int arr[1000][1000]; //�丶�䰡 �ִ°� ���°�?
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
			d[i][j] = -1; //�湮�� ���� ������ -1�� �ʱ�ȭ�� ��� ������. (�׷��� �ش� ���� ���� ������ ������)
			if (arr[i][j] == 1) { //���� �ش� ��ġ�� �丶�䰡 �ִٸ� �ű⼭���� ������ ��.
				q.push(make_pair(i, j)); //queue�� push.
				d[i][j] = 0; //�湮�� 0���� ǥ��
			}
		}
	}

	//���⼭ d�迭�� � ������ �ϴ��� �˾Ƶ���. d �迭�� -1�� �ʱ�ȭ �Ǿ��ְ�, �� ���¿���, arr�迭�� 1�� ������ �����ϴ� �� ����
	//0���� ������. ������ �� �ڸ��� �� �����̱� ������. �� �ڸ��� �� ���� �丶�䰡 ��ġ�� ���̰�, �ű⼭���� �Űܰ��� ������.

	while (!q.empty()) {
		//ť���� ���� ���� ������
		int x = q.front().first;
		int y = q.front().second;
		q.pop();

		//�ش� ������ �ֺ���ġ�� Ȯ��
		for (int i = 0; i < 4; i++) {
			int curX = x + dirX[i];
			int curY = y + dirY[i];
			//���� check.
			if ((0 <= curX && curX < n) && (0 <= curY && curY < m)) { //�ȿ� ����ִ�?
				if (arr[curX][curY] == 0 && d[curX][curY] == -1) { //arr �迭�� ���� 0�ε�, ���� �湮���� �ʾҴ�. ��� ����.
					d[curX][curY] = d[x][y] + 1; //���� �ش� ��ġ +  1 �� ����. 
					q.push(make_pair(curX, curY)); //�ش� �ε����� �ٽ� queue�� �־���.
				}
			}
		}
	}
	int answer = 0; 

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			if (answer < d[i][j]) {
				answer = d[i][j]; //answer�� �迭������ ���� ū ����.
			}
		}
	}

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			if (arr[i][j] == 0 && d[i][j] == -1) {
				answer = -1; //�ϳ���, ���� �ʾҴµ� �湮���� ���� ���� �ִٸ� answer�� -1
			}
		}
	}

	cout << answer << "\n";
	return 0;
}