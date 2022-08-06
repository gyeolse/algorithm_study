#include <iostream>
#include <stack>

using namespace std;

int n;
int result;

int main(void) {
	cin.tie(NULL);
	ios::sync_with_stdio(false);
	stack <int> stk;

	cin >> n;
	for (int i = 0; i < n; i++) {
		int temp;
		cin >> temp;
		if (temp == 0) {
			stk.pop();
		}
		else {
			stk.push(temp);	
		}
	}
	while (!stk.empty()) {
		result += stk.top();
		stk.pop();
	}
	cout << result << "\n";
	return 0;
}