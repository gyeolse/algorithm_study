#include <iostream>
#include <string>

using namespace std;

int a, b, c, result;

char arr[10] = {'0','1','2','3','4','5','6','7','8','9'};
int output[10];

string s_result;

int main(void) {
	cin.tie(NULL);
	ios::sync_with_stdio(false);

	cin >> a >> b >> c;

	result = a * b * c;
	s_result = to_string(result);
	
	for (int i = 0; i < s_result.size(); i++) {
		for (int j = 0; j < 10; j++) {
			if (s_result[i] == arr[j]) {
				output[j]++;
			}
		}
	}
	
	for (int i = 0; i < 10; i++) {
		cout << output[i] << "\n";
	}
	return 0;
}