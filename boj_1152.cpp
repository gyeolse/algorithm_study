#include <string>
#include <iostream>
#include <queue>

using namespace std;
/*
	* 처음에 큐로 구현을 했는데 틀림. 왜 틀린지 모르겠음.. 출력도 같이 나왔는데 왜 그런건지 모르겠다.
	* if로 특별한 case 구분함.
*/
int main(void) {
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	string test;
	string temp;
	int cnt=1;

	getline(cin, test); //줄 그대로 받는 getline. cin을 활용한 사용법

	for (int i = 0; i<test.length(); i++) {
		if (test[i] == ' ') {
			cnt++;
		}
	}
	if (test[0]== ' ') {
		cnt--;
	}
	if (test[test.length()-1] == ' ') {
		cnt--;
	}

	cout << cnt << "\n";
	return 0;
}