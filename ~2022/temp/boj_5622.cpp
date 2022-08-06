#include <iostream>
#include <string>
#include <queue>

using namespace std;

int total_time;
string input;

string hal_num = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";
int idx[9] = { 2,3,4,5,6,7,8,9 };

//string 배열의 idx의 숫자에 따라서 해당 숫자를 결정하는걸로

//배열의 idx +1 이 곧 걸리는 시간

				//012 345 678 91011 121314 15161718 192021 22232425
queue <int> mylist;

int check(int j) {
	if (j < 3) {
		return 2;
	}
	else if (j >= 3 && j < 6) {
		return 3;
	}
	else if (j >= 6 && j < 9) {
		return 4;
	}
	else if (j >= 9 && j < 12) {
		return 5;
	}
	else if (j >= 12 && j < 15) {
		return 6;
	}
	else if (j >= 15 && j < 19) {
		return 7;
	}
	else if (j >= 19 && j < 22) {
		return 8;
	}
	else
		return 9;
}
int main(void) {
	cin.tie(NULL);
	ios::sync_with_stdio(false);
	cin >> input;
	for (int i = 0; i < input.size(); i++) {
		for (int j = 0; j < hal_num.size(); j++) {
			if (input[i] == hal_num[j]) {
				int temp = check(j);
				total_time += (temp+1);
			}
		}
	}
	cout << total_time << "\n";
	return 0;
}