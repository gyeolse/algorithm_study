#include <iostream>
#include <deque>

using namespace std;

int n;
deque <int> card_list;
int result;

int main(void) {
	ios::sync_with_stdio(false);
	
	cin >> n;

	for (int i = 0; i < n; i++) {
		card_list.push_back(i+1);
	}

	while (!card_list.empty()) {
		if (card_list.size() == 1) {
			cout << card_list.front() << "\n";
		}
		
		card_list.pop_front();
		if (card_list.size() > 0) {
			int temp = card_list.front();
			card_list.push_back(temp);
			card_list.pop_front();
		}
	}

	return 0;
}