/*
 * 점수가 특정 조건을 만족할 때에만 사용
 * 특정 조건 -> 캐릭터 점수를 N, 점수 N의 자릿수를 기준으로 반으로 나누어, 
 * 왼쪽 부분의 각 자릿수의 합과 오른쪽 부분의 자릿수의 합을 더한 값이 동일한 경우
 * 
 * ex. 123402라면 1+2+3 == 4+0+2
 * 사용이 가능하다면, LUCKY 아니라면 READY
 * 항상 짝수, 
*/

#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

string input;

int main(void) {
    cin>>input;

    int testSize = input.size();

    int num1=0, num2=0;

    for(int i=0;i<testSize/2;i++){
        num1 +=input[i]-'0';
    }

    for(int i=(testSize/2);i<input.size();i++){
        num2 += input[i]-'0';
    }
    if(num1!=num2)   cout<<"READY"<<"\n";
    else cout<<"LUCKY"<<"\n";

    return 0;
}