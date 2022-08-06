#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
using namespace std;
int arr[10];
int input[10];
bool isUsed[10];
int n,m;

//isUsed 배열 체크 조건 또 뺴먹음
//set 선언 및 사용법 때문에 이거 무조건 한번 더 풀어야함.

set<vector<int>> res;
void func(int idx){
    if(idx==m){
        vector<int> v;    
        for(int i=0;i<m;i++){
            v[i] = arr[i];
//            v.push_front(arr[i]);
        }
        res.insert(v);
        return;
    }

    for(int i=0;i<n;i++){
        if(!isUsed[i]){
            isUsed[i] = true; //중복이 되면 안되니까 빼면 안되는 거였는데, 어리석었다. 
            arr[idx] = input[i];
            func(idx+1);
            isUsed[i] = false;
        }
    }
}

int main(void){
    cin.tie(NULL);
    ios::sync_with_stdio(false);
    cin>>n>>m;    
    for(int i=0;i<n;i++){
        cin>>input[i];
    }
    sort(input, input+n);
    func(0);
/*
    for(auto it=res.begin();it!=res.end();it++){
        for(int j=0;j<it->size();j++){
            cout<<it->at(j)<<" ";
        }
        cout<<endl;
    }
*/
    for(auto it : res){
        for(int i=0;i<it.size();i++){
            cout<<it[i]<<" ";
        }
        cout<<'\n';
    }
    return 0;
}