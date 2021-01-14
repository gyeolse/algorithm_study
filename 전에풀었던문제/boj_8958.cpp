#include <iostream>
#include <string>

using namespace std;

int n;
int result;
int temp;

void check(char str[], int n) {
	if (str[n] == 'O') {
		temp++;
		check(str, n - 1);
	}
}

int main(void) {
	cin.tie(NULL);
	ios::sync_with_stdio(false);

	cin >> n;
	for (int i = 0; i < n; i++) {
		result = 0;
		char input[80];

		cin >> input;
		int j = 0;
		while (input[j]) {
			if (input[j] == 'O') {
				check(input,j);
				result += temp;
				temp = 0;
			}
			j++;
		}
		cout << result<<'\n';
	}
}