#include <iostream>
#include <algorithm>

using namespace std;

int input[9];
int sum;
int main(void){
//test
//test2
    for(int i=0;i<9;i++){
        cin>>input[i];
        sum +=input[i];
    }

    sort(input,input+9);

    for(int i=0;i<9;i++){
        for(int j=i+1;j<9;j++){
            if(sum-input[i]-input[j]==100){
                for(int k=0;k<9;k++){
                    if(i==k||j==k) continue;
                    cout<<input[k]<<'\n';
                }
                return 0;
            }
        }
    }

}