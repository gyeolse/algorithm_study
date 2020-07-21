#include <iostream>

using namespace std;
int n,m; //1번부터 ~ n번까지 중 길이가 m인 수열
int arr[10]; //출력할 숫자들을 저장해놓는 배열
bool isUsed[10];  // 사용했냐 안했냐

//func의 의미 k번째까지의 수들을 확정시키는 함수를 말한다.
void func(int idx){
    int k;
    if(idx==m){
        for(k=0;k<m-1;k++){
//            cout<<"K의 값 : "<<k<<" "<<endl; 오름차순만 촐력할라고
            if(arr[k]>arr[k+1]) break;
        }
        if(k==m-1){
            for(int i=0;i<m;i++){
                cout<<arr[i]<<" ";
            }
            cout<<"\n";
        }
        return;
    }

    for(int i=1;i<=n;i++){ //n번만큼 시행해야 함. 
        if(!isUsed[i]){ //사용 안했을때만 들어가겠지
            //사용했다
            isUsed[i]= true;
            //배열에 넣어라
            arr[idx] = i;
            //다음으로 이동해라
            func(idx+1);
            isUsed[i]=false; //다시 사용을 초기화 시킴.
        }
    }
}
int main(void){
    cin>>n>>m;

    func(0);
    return 0;
}