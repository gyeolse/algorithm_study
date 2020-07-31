#include <iostream>
#include <algorithm>
using namespace std;

int board[11][11];
int isUsed1[20]; // /쪽 방향
int isUsed2[20]; // \쪽 방향
int n;
int res[2]; //0= black, 1=white

void func(int x, int y, int cnt, int color) {
	//증가
	if (y >= n) {
		x++;
		if (y % 2 == 0) y = 1;
		else y = 0;
	}
	//base condition
	if (x >= n) {
		res[color] = max(res[color], cnt); //저장된 color와 cnt를 비교
		return;
	}

	//back-tracking
	if (board[x][y] && isUsed2[x - y + n - 1] == 0 && isUsed1[x + y] == 0 ) {
		isUsed1[x + y] = 1;
		isUsed2[x - y + n - 1] = 1;
		func(x, y + 2, cnt + 1, color);
		isUsed1[x + y] = 0;
		isUsed2[x - y + n - 1] = 0;
	}
	func(x, y + 2, cnt, color);
}
int main(void) {    
    cin.tie(NULL);
    cout.tie(NULL);
    ios::sync_with_stdio(false);
	cin >> n;

    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            cin>>board[i][j];
        }
    }
	func(0, 0, 0, 0);
	func(0, 1, 0, 1);
	cout << res[0] + res[1];
	return 0;
}