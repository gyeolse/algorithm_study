//10974. 모든 순열 

#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int n;
int test_case = 1;


int main(void){
	cin>>n;
	vector <int> vec(n);
	for(int i=0;i<n;i++){
		vec[i] = i+1;
	}	
	for(int i=1;i<=n;i++){
		test_case = test_case * i;
	}
	
	for(int i=0;i<n;i++){
		cout<<vec[i]<<" ";
	}
	cout<<'\n';
	
	for(int i=1;i<=(test_case-1);i++){				
		if(next_permutation(vec.begin(),vec.end())==0){
			return 0;
		}
		else{
			for(int i=0;i<n;i++){
			cout<<vec[i]<<" ";
		}
		
		}
		cout<<"\n";
	}
	return 0;
}
