#include <iostream>

int result[1000];

int idx, K;

using namespace std;
/*
	* 1~N ���� N���� ����� ���� �̷�� ����. ���� ���� K
	* ������� K��° ����� ����. �ѻ�� ���Ž�, ���� ������ �̷���� ���� ���� �ݺ�
	* N���� ����� ��� ���ŵ� ������
	* ex. <7,3>
	7���� ���. 3��° ��� ����
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
