// 4673
#include <iostream>
#include <string>

using namespace std;

int MAX = 10000;
int arr[10000]; //1,2,3,,,,10000이 들어갈 배열
bool visit[10000]; //방문했는지 안했는지 확인

void init() {
	for (int i = 0; i < 10000; i++) {
		int temp = i;
		arr[i] = temp;
	}
	memset(visit, false, sizeof(visit));
}

void d(int temp) {
	int result = 0; //결과값.
	result += temp; //스스로 더하고,
	visit[temp] = true; //방문 true 설정
	string s_temp = to_string(temp); //string으로 형변환
	for (int i = 0; i < s_temp.size(); i++) {
		char c_ = s_temp[i]; 
		result += c_ - '0'; // 각 수 만큼 더해줌
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