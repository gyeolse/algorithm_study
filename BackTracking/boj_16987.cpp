#include <iostream>
#include <algorithm>
#include <cstring>
#include <vector>

using namespace std;
int n;
int weight[10]; //무게
int naegudo[10]; //내구도
int res;

void func(int idx, int cnt) {
	if (idx == n) {
		res = max(res, cnt);
		return;
	}

	if (naegudo[idx] <= 0) return func(idx + 1, cnt); 

	for (int i = 0; i < n; i++) {
		if (idx == i || naegudo[i] <= 0) continue;
		naegudo[i] -= weight[idx];
		naegudo[idx] -= weight[i];
		int t = 0;
		if (naegudo[idx] <= 0) t++;
		if (naegudo[i] <= 0) t++;

		func(idx + 1, cnt + t);
		naegudo[i] += weight[idx];
		naegudo[idx] += weight[i];
	}

	res = max(res, cnt);
}

int main(void) {
	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> naegudo[i]>>weight[i];
	}
	func(0,0);
	
	cout << res << '\n';
	return 0;
}