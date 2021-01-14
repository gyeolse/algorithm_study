#include <iostream>
using namespace std;
int n,s; //정수의 개수 n개. 정수 s
int arr[30]; //최대 20개까지 들어감
bool isUsed[30];
int cnt=0;

void func(int idx, int tot){
    if(idx==n){
        if(tot==s) cnt++;
        return;
    }
    func(idx+1,tot);
    func(idx+1,tot+arr[idx]);
}

int main(void){
    cin.tie(NULL);
    ios::sync_with_stdio(false);
    cin>>n>>s;

    for(int i=0;i<n;i++){
        cin>>arr[i];
    }
    func(0,0);
    if(s==0) cnt--;
    cout<<cnt;
    return 0;
}