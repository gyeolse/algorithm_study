//10819번. 차이를 최대로
/*
    1. 접근법은 맞았지만, run-time error. 아마 vector 관련 문제일 것 같음.
    2. 차이를 최대로 문제는 do while 문을 이용해서 풀면 좀 더 편리하게 풀 수 있다. 
*/

#include <iostream>
#include <vector>
#include <algorithm>
#include <math.h>

using namespace std;

//각자의 케이스를 각자의 배열에 저장함.
//max를 출력함

int n;
int test_case;
int calculate(vector<int> &v){
	int sum=0;
	for(int i=1;i<v.size();i++){
		sum +=abs(v[i]-v[i-1]);
	}
	
	return sum;
}

int main(void){
	cin>>n;	

	vector <int> vec(n);
	//집어넣고 정렬 수행
	for(int i=0;i<n;i++){
		cin>>vec[i];
	}
	sort(vec.begin(),vec.end()); //1st.
	
	int result = 0;
	do {
		int temp = calculate(vec);
		result = max(result,temp);
	} while(next_permutation(vec.begin(),vec.end()));

	cout<<result<<"\n";
	return 0;
	
}
