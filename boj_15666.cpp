#include <iostream>
#include <set>
#include <vector>
using namespace std;
int n,m;
//bool isUsed[10];
int input[10];
int arr[10];
bool isUsed[10];
set<vector<int>> res;

void func(int idx){
    if(idx==m){
        int k;
        for(k=0;k<m-1;k++){
            if(arr[k]>arr[k+1]) break;
        }        
        if(k==m-1){
            vector<int> temp;
            for(int i=0;i<m;i++){
                temp.push_back(arr[i]);
            }
            res.insert(temp);
        }        
        return; 
    }

    for(int i=0;i<n;i++){
            arr[idx] = input[i];
            func(idx+1);
        
    }

}
int main(void){
    cin>>n>>m;
    for(int i=0;i<n;i++){
        cin>>input[i];
    }

    func(0);
    
    for(auto it : res){
        for(int i=0;i<it.size();i++){
            cout<<it[i]<<" ";
        }
        cout<<"\n";
    }

    return 0;
}