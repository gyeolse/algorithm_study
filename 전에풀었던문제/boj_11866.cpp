#include <iostream>

int result[1000];

int idx, K;

using namespace std;
/*
	* 1~N 까지 N명의 사람이 원을 이루며 앉음. 양의 정수 K
	* 순서대로 K번째 사람을 제거. 한사람 제거시, 남은 사람들로 이루어진 원을 따라 반복
	* N명의 사람이 모두 제거될 때까지
	* ex. <7,3>
	7명의 사람. 3번째 사람 제거
	1, 2, 3, 4, 5, 6, 7
	1, 2, 4, 5, 6, 7
	1, 2, 4, 5, 7
	1, 4, 5, 7
	1, 4, 5
	1, 4
	4,
	0
	3. 6. 2. 7. 5.  1. 4
*/

class que {
public:
	int arr[1000];
	int front, rear;
	int sz;
	bool isEmpty();

	que(int n) {
		sz = n;
		rear = sz - 1;
		front = 0;
	}

	void pop();
	
	void push(int idx,int n) {
		if (isEmpty() == 0) {
			return;
		}
		else {
			arr[idx%sz] = n;
			front = (front + 1) % sz;

		}
	}

	int pop(int idx, int n) {
		if (isEmpty() == 0) {
			return;
		}
		else {
			int temp = arr[idx % sz];
			arr[idx % sz] = 0;
			return temp;
		}
	}

	bool isEmpty() {
		if (rear == front) {
			return true;
		}
		else
			return false;
	}
};

int main(void) {

	cin >> idx >> K;

	que myque(idx);

	for (int i = 0; i < idx; i++) {
		myque.arr[i] = i + 1;
	}

	while (myque.isEmpty() != 0) {
		
	}
	

	return 0;
}
