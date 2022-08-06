#include <iostream>
#include <cstring>
#include <algorithm>

using namespace std;

int arr[50][50]; //���߹�
int dirX[] = { 0,0,1,-1 };
int dirY[] = { 1,-1,0,0 };
bool visit[50][50];
int test, m, n, k; //m�� n�� �ùٸ� �������� Ȯ���� �� ������ ��.

bool isInside(int y1, int x1) {
	return (y1 >= 0 && y1 < n) && (x1 >= 0 && x1 < m); //#1. �ùٸ� �������� �ִ��� Ȯ�� 
}

void dfs(int y, int x) {

	if (visit[y][x]==true)
		return;
	visit[y][x] = true;

	for (int i = 0; i < 4; i++) {
 		int arrY = y + dirY[i];
		int arrX = x + dirX[i];
		if (isInside(arrY, arrX) && arr[arrY][arrX]==1) {
			dfs(arrY, arrX);
		}
	}

}

int main(void) {
	//test case, ���� m, ���� n, ��ġ ���� k
	cin >> test;
	for (int i = 0; i < test; i++) {
		memset(visit, false, sizeof(visit));
		memset(arr, 0, sizeof(arr));
		cin >> m >> n >> k;
		int cnt = 0;

		for (int j = 0; j < k; j++) {
			int y, x;
			cin >> x >> y;
			arr[y][x] = 1;
		}
		
		for (int j = 0; j < n; j++) {
			for (int k = 0; k < m; k++) {
				if (arr[j][k] && visit[j][k]==false) {
					cnt++;
					dfs(j, k);
				}
			}
		}
		cout << cnt << "\n";		
	}
}