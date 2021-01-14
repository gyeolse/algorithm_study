#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int n, score;
int max_score;
vector <int> total;
double arr[1000];
double result;

int main(void) {
	cin >> n;

	for (int i = 0; i < n; i++) {
		cin >> score;
		total.push_back(score);
	}
	max_score = *max_element(total.begin(), total.end());

	for (int i = 0; i < n; i++) {
		double temp = (double)total[i]/max_score*100;
		result += temp;
	}

	cout << fixed;
	cout.precision(2);
	cout << result / n << endl;
	return 0;

}