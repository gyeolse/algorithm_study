//6603번. 로또

#include <vector>
#include <iostream>
#include <algorithm>

using namespace std;
/*
	******몰랐으니 알아두자.
	** 제일 중요한 부분 :  0과 1을 넣어주어야함.
				이유 : 해당 0,1 을 넣어주면, 해당 1에 대응하는 수만 출력을 할 수 있음.
				즉, 0은 출력을 하지 않고, 1을 출력하기 때문에 중복이 되지도 않음.
	*** auto연산자를 이용할 경우. vector 선언시 초기화 시켜주지 말자.
	**** auto 연산자 특징에 대해서 공부하기.
*/

int main(void){
	
	int n;
	while(1){
		cin>>n;
		if(n==0){
			break;
		}
		vector <int> a(n);
		for(int i=0;i<n;i++){
			cin>>a[i];
		}
		//다른 것 1
		vector <int> d(n); //이거 오류찾느라 30분 씀. 왜 d(n)넣고 난리였는지;
		//왜 d(n) 이 안되느냐 : 이유. auto 연산자 때문임. auto 연산자 말고 for문으로 돌리면
		//해결가능함. 하 시벌탱
		
		//0을 k-6개, 1을 6개 넣는 이유? 위에 씀.
		for(int i=0;i<n-6;i++){
			d[i]=0;
		}
		for(int i=n-6;i<n;i++){
			d[i]=1;
		}
		
		//이유		
		vector<vector<int>> ans;
		do{
			vector<int> cur;
			for(int i=0;i<n;i++){
				if(d[i]==1) //1인 경우만 
					cur.push_back(a[i]); //출력할 cur 벡터
			}
			ans.push_back(cur); //current vector를 answer vector에 넣음.
		} while(next_permutation(d.begin(),d.end()));		
		sort(ans.begin(),ans.end());
		
		
		for(int i=0;i<ans.size();i++){
			for(int j=0;j<ans[i].size();j++){
				cout<<ans[i][j]<<" ";
			}
			cout<<'\n';
		}
	
		cout<<"\n";
	}
		return 0;

}
