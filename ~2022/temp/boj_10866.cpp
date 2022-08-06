#include <iostream>
#include <deque>

using namespace std;

deque <int> deq;
int n;
string s;

int main(void) {
	cin >> n;

	for (int i = 0; i < n; i++) {
		cin >> s;
		int temp;
		if (s == "push_front") {
			cin >> temp;
			deq.push_front(temp);
		}
		else if (s == "push_back") {
			cin >> temp;
			deq.push_back(temp);
		}
		else if (s == "pop_front") {
			if (deq.empty()==1) {
				cout << -1 << "\n";
			}
			else {
				int num = deq.front();
				cout << num << "\n";
				deq.pop_front();
			}
		}
		else if (s == "pop_back") {
			if (deq.empty() == 1) {
				cout << -1 << "\n";
			}
			else {
				int num = deq.back();
				cout << num << "\n";
				deq.pop_back();
			}
		}
		else if (s == "size") {
			cout << deq.size() << "\n";
		}
		else if (s == "empty") {
			cout << deq.empty() << "\n";
		}
		else if (s == "front") {
			if (deq.empty() == 1) {
				cout << -1 << "\n";
			}
			else {
				cout << deq.front() << "\n";
			}
		}
		else if (s == "back") {
			if (deq.empty() == 1) {
				cout << -1 << "\n";
			}
			else {
				cout << deq.back() << "\n";
			}
		}
	}

	return 0;
}