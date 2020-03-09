#include <iostream>
using namespace std;

int input[10];
int visit[42] = { 0 };
int cnt = 0;

int main(void) {
	cin.tie(NULL);
	ios::sync_with_stdio(false);

	for (int i = 0; i < 10; i++) {
		cin >> input[i];
		visit[input[i]%42] = 1;
	}

	for (int i = 0; i < 42; i++) {
		if (visit[i] == 1) {
			cnt++;
		}
	}

	cout << cnt << "\n";
	return 0;
}