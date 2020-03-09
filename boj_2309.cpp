#include <iostream>
#include <algorithm>

using namespace std;

int input[9];
int sum;
int main(void){

    for(int i=0;i<9;i++){
        cin>>input[i];
        sum +=input[i];
    }

    sort(input,input+9);

    for(int i=0;;i++){
        for(int j=0;j<i;j++){
            if((sum-input[i]-input[j])==0){
                return 0;
            }

        }
    }

    
    return 0;   
}