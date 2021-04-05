#include <bits/stdc++.h>
using namespace std;

stack<char> stk;
string s; 

int main() {
    cin>>s;

    int temp = 1;
    int res = 0;
    bool isAvailable = true;

    for(int i=0;i<s.size();i++) {
        // (일 경우, temp에 값을 더해줌
        if(s[i] == '(') {
            temp *= 2;
            stk.push(s[i]);
        }

        //[일 경우, temp에 값을 더해줌
        else if(s[i] == '[') {
            temp *=3;
            stk.push(s[i]);
        }

        //)일 경우
        else if(s[i] == ')' && (stk.size() == 0 || stk.top() != '(' )) {
            isAvailable = false;
            break;
        }

        else if(s[i] == ']' && (stk.size() == 0 || stk.top() !='[' )) {
            isAvailable = false;
            break;
        }

        else if (s[i] == ')') {
            if(s[i-1] == '(') {
                res += temp;
            }
            stk.pop();
            temp /=2;

        }

        else if(s[i] == ']') {
            if(s[i-1] == '[') {
                res += temp;
            }
            stk.pop();
            temp /=3;
        }        
    }

    //stack이 비어있지 않거나, 올바르지 않은 괄호일 경우 
    if(stk.size() != 0 || !isAvailable ) {
        cout<<0<<"\n";
    }
    else {
        cout<<res<<"\n";
    }

    return 0;
}