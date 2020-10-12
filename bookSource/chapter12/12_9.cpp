#include <string>
#include <vector>
#include <iostream>
#include <algorithm>
#include <stack>
using namespace std;

int solution(string s) {
    int answer = s.size(); //압축 못한다면 원래 size 값이 곧 답이 됨. 

    for (int step=1;step < s.size()/2 + 1 ; step++){ //최대 비교
        string _zip = "";
        string _prev = s.substr(0,step); //step 만큼 맨 처음 값의 문자열 추출
        int cnt=1;
        for(int j=step; j<s.size(); j += step) {
            if(_prev == s.substr(j,step)) cnt++;
            else {
                _zip += (cnt>=2) ? to_string(cnt) + _prev : _prev;
                _prev = s.substr(j,step);
                cnt = 1;
            }
        }

        _zip += (cnt>=2) ? to_string(cnt) + _prev : _prev;
        answer = min(answer, (int)_zip.size());
    }
    return answer;
}

int main(void){
    while(1){
        string input;
        cin>>input;
        cout<<solution(input)<<endl;
    }
    return 0;

}