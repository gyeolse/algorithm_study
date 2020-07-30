#include <iostream>
using namespace std;
long long a_,b_,c_;

long long func(long long a, long long b, long long c){
    //나머지를 출력
    //a를 b번 곱한 수를 c로 나눈 나머지를 출력
    if(b==1) return a%c; //base condtion
    long long temp = func(a,b/2,c);
    temp = temp * temp % c;
    if(b%2==0) return temp;
    return temp*a%c;
}
int main(void){
    cin.tie(NULL);
    cout.tie(NULL);
    ios::sync_with_stdio(false);

    cin>>a_>>b_>>c_;
    cout<<func(a_,b_,c_)<<"\n";
    return 0;
}