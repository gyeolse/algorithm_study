#include <iostream>
#include <string>
#include <string.h>

using namespace std;

//���ĺ� ö�� Ʋ���� ��� ���ٸԾ���;;
string test;
string alpha = "abcdefghijklmnopqrstuvwxyz";

int idx[26];

int main(void) {
	cin.tie(NULL);
	ios::sync_with_stdio(false);
	memset(idx, -1, sizeof(idx));

	cin >> test;
	for (int i = 0; test[i]!='\0' ; i++) {
		for (int j = 0; j < 26; j++) {
			if (idx[j] == -1 && alpha[j] == test[i]) {
				idx[j] = i;
			}
		}
	}

	for (int i = 0; i < 26; i++) {
		cout << idx[i] << " ";
	}
	cout << "\n";

	return 0;
}