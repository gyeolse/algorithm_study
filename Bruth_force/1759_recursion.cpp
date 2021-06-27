// https://m.blog.naver.com/PostView.nhn?blogId=and_lamyland&logNo=221364608127&proxyReferer=https:%2F%2Fwww.google.com%2F

#include <bits/stdc++.h>
using namespace std;
int l, c;
vector<char> vec;
bool isAvailable(string s) {
    int ja = 0;
    int mo = 0;

    for(int i=0;i<s.size();i++) {
        if(s[i] == 'a' || s[i] == 'e' || s[i]=='i' || s[i] =='o' || s[i]=='u') {
            mo++;
        }
        else {
            ja++;
        }
    }
    
    if(ja>=2 && mo >=1) {
        return true;
    }
    else {
        return false;
    }
}

void func(string s, int idx) { //스트링, 사용한 idx

    //1. 탈출 조건
    if(s.size() == l) {
        if(isAvailable(s)==true) {
            cout<<s<<"\n";
        }
        return;
    }

    //2. 길이 초과시 return
    if(idx >=vec.size() ) return;
    
    //3. 다음으로 이동하는 조건
    func(s+vec[idx],idx+1);
    cout<<"s called : "<<s<<" idx length : "<<idx<<"\n";
    func(s,idx+1);
}
int main() {
    cin >> l >> c;

    for (int i = 0;i < c;i++) {
        char x; cin>>x; vec.push_back(x);
    }

    sort(vec.begin(),vec.end());

    // for(int i=0;i<vec.size();i++) {
    //     cout<<vec[i]<<" ";
    // }
    //string의 길이, 자음 갯수, 모음 갯수, 
    //탈출조건 : 길이가 l, 모음, 자음 조건 위배 X면 출력후 return;
    string s="";
    func(s,0);
    return 0;
}