#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

string input;
int MAX = 0;
int cnt = 0;
int idx;
int a[26] = { 0, };

int main(void) {
	cin.tie(NULL);
	ios::sync_with_stdio(false);
	
	string c;
	cin >> c;
	transform(c.begin(), c.end(), c.begin(), (int(*)(int))toupper);
	for (int i = 0; i < c.length(); i++) {
		a[c[i] - 'A']++;
	}
	for (int i = 0; i < 26; i++) {
		if (MAX < a[i]) {
			MAX = a[i];
			cnt = 0;
			idx = i;
		}
		if (MAX == a[i])
			cnt++;
	}
	if(cnt>1){
		cout << "?";
	}
	else {
		cout << (char)(idx + 'A');
	}
	return 0;
}