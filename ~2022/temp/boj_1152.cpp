#include <string>
#include <iostream>
#include <queue>

using namespace std;
/*
	* ó���� ť�� ������ �ߴµ� Ʋ��. �� Ʋ���� �𸣰���.. ��µ� ���� ���Դµ� �� �׷����� �𸣰ڴ�.
	* if�� Ư���� case ������.
*/
int main(void) {
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	string test;
	string temp;
	int cnt=1;

	getline(cin, test); //�� �״�� �޴� getline. cin�� Ȱ���� ����

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