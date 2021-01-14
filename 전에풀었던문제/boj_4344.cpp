#include <iostream>
#include <string.h>

using namespace std;

int n, student; //test case

int arr[1000];
int score[1000];
int result, cnt;
double st_avg;
double output;

void init() {
	memset(score, 0, sizeof(score));
	student = 0;
	result = 0;
	cnt = 0;
	st_avg = 0;
}

int main(void) {
	cin.tie(NULL);
	ios::sync_with_stdio(false);

	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> student;
		for (int j = 0; j < student; j++) {
			cin >> score[j];
			result += score[j];
		}
		st_avg = double(result / student);
		
		for (int k = 0; k < student; k++) {
			if (st_avg < score[k]) {
				cnt++;
			}
		}

		output = (double)cnt/student*100;
		cout << fixed; //ÀÚ¸´¼ö °íÁ¤
		cout.precision(3); //ÀÚ¸´¼ö °íÁ¤
		cout<< output << "%" << "\n";
		init();

	}
	return 0;
}