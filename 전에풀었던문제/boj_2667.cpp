#include <iostream>
#include <algorithm>
#include <cstdio>

using namespace std;

int map[25][25]; //����
int arrSize[323]; //ũ�Ⱑ n�϶� ���� �ִ� ����
int dir[4][2] = { {-1,0},{1,0},{0,-1},{0,1} }; //�����¿� Ȯ���� ���� 2���� �迭
int cnt; //������ ����
int n; //�Է¹��� n

//true�� ��쿡��, return true. 0���� �۴ٰų�, n�� a���� ū ���� return false
bool isInside(int a, int b) {
	return (a >= 0 && a < n) && (b >= 0 && b < n);
}

void dfs(int a, int b, int key) {
	map[a][b] = key; //key�� ������ number���� ����
	//������ȣ�� map�� ���� reset��Ŵ
	for (int i = 0; i < 4; i++) { //x,y ���⿡ ���缭 ����Ž��
		int dy = a + dir[i][0]; //y 
		int dx = b + dir[i][1]; //x 

		if (isInside(dy, dx) && map[dy][dx] == 1) { //�������� �����ϴ� index�� 1�� ���� ���
			dfs(dy, dx, key); //���. dfs ����.
		}
	}
}

void Solution(int n) {
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			if (map[i][j] == 1) {
				cnt++; //���� ��ȣ ++ ���ֱ� 
				dfs(i, j, cnt + 1); //1�� ���, �� ���������� dfs ����
			}
		}
	}

	for (int i = 0; i < n; i++) { //�� dfs���� ���� �����ص�.
		for (int j = 0; j < n; j++) {
			//map[i][j]>2�϶�����. 2-2=0, 3-2=1, 4-2=2....
			//--- arrSize[0],[1],[2]�� ++�ϴ� ����.  
			if (map[i][j] > 1) { 
				arrSize[map[i][j] - 2]++;
			}
		}
	}
}

int main(void) {
	cin >> n;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			scanf_s("%1d", &map[i][j]);
		}
	}
	Solution(n);
	sort(arrSize, arrSize + cnt); //���� (��������)
	cout << cnt << endl;
	for (int i = 0; i < cnt; i++) {
		cout << arrSize[i] << endl;
	}

	return 0;
}