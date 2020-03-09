// 4673
#include <iostream>
#include <string>

using namespace std;

int MAX = 10000;
int arr[10000]; //1,2,3,,,,10000�� �� �迭
bool visit[10000]; //�湮�ߴ��� ���ߴ��� Ȯ��

void init() {
	for (int i = 0; i < 10000; i++) {
		int temp = i;
		arr[i] = temp;
	}
	memset(visit, false, sizeof(visit));
}

void d(int temp) {
	int result = 0; //�����.
	result += temp; //������ ���ϰ�,
	visit[temp] = true; //�湮 true ����
	string s_temp = to_string(temp); //string���� ����ȯ
	for (int i = 0; i < s_temp.size(); i++) {
		char c_ = s_temp[i]; 
		result += c_ - '0'; // �� �� ��ŭ ������
	}
	visit[result] = true; 	
}

int main(void) {
	ios::sync_with_stdio(false);

	init();

	for (int i = 0; i < MAX; i++) {
		if (visit[i] == true) {
			continue;
		}
		d(i);
	}

	for (int i = 0; i < MAX; i++) {
		if (visit[i] == false) {
			cout << arr[i] << "\n";
		}
	}

	return 0;
}