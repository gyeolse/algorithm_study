//1476번. 날짜 계산
// 1을 빼주는 이유. 1을 빼면 해당 수보다 작은 자연수 중에서 이를 만족하는 것을 찾는 문제임.
/* 
  시간초과가 나서 계속 틀렸음.
  간결하게 해주기 위해서, mod, if문 사용.
  알아둘 것.
*/
#include <iostream>

using namespace std;
int le,ls,lm;
int main(void){
	cin.tie(NULL);
	ios::sync_with_stdio(false);
	cin>>le>>ls>>lm;
	le-=1;
	ls-=1;
	lm-=1;	

	//이렇게 간결하게 쓸 수 있다는 게 놀라움.
	for(int i=0;;i++){
		if(i%15 == le && i%28 == ls && i%19 ==lm){
			cout<<i+1<<'\n';
			break;
		}
	}
	
	return 0;
}
