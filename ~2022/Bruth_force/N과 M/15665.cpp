#include <iostream>
#include <set>
#include <algorithm>
#include <vector>
using namespace std;
int n, m;
int arr[10];
int input[10];
bool isUsed[10];
set<vector<int>> res;

void func(int idx) {
	if (idx == m) {
		vector<int> temp;
		for (int i = 0; i < m; i++) {
			temp.push_back(arr[i]);
		}
		res.insert(temp);
		return;
	}

	for (int i = 0; i < n; i++) {
		arr[idx] = input[i];
		func(idx + 1);
	}
}

int main(void) {
	cin >> n >> m;
	for (int i = 0; i < n; i++) {
		cin >> input[i];
	}
	sort(input, input + n);
	func(0);
	for (auto it : res) {
		for (int i = 0; i < it.size(); i++) {
			cout << it[i] << " ";
		}
		cout << "\n";
	}
	return 0;
}