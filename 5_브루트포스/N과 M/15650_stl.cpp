#include <bits/stdc++.h>
using namespace std;

//문제 : 중복되는 수열 여러번 출력 불가

int n,m;
int arr[10];
vector<int> chk;

int main(){
    cin>>n>>m; //5 3. 5개 중 3개
    for(int i=0;i<n;i++){
        arr[i] = i+1;
    }
    
//1. 이 짓을 왜하는가? 
    for(int i=0;i<m;i++){
        chk.push_back(0); 
    }    
    for(int i=0;i<(n-m);i++){
        chk.push_back(1); 
    }

    sort(chk.begin(),chk.end()); //2. 이 짓도 왜 하는가?
    do {
        for(int i=0;i<n;i++){
            if(chk[i]==0){
                cout<<arr[i]<<" ";
            }
        }
        cout<<"\n";
    } while(next_permutation(chk.begin(),chk.end()));

    return 0;
}