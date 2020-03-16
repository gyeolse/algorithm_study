//1991. map

/*
    (1) pair 구조체 first, second; //IN utility
    (2) typedef 구조체 정의 별칭 지정.
    
*/
#include <iostream>
#include <map>
#include <utility>
using namespace std;
int n;

typedef pair<char, char> pr;
map<char,pr> mp;
//key 자료형, value 자료형, 변수

//preorder
//postorder
//inorder
void preorder(char A){
    if(A=='.') return;
    cout<<A;
    preorder(mp[A].first);
    preorder(mp[A].second);
}

void inorder(char A){
    if(A=='.') return;
    inorder(mp[A].first);
    cout<<A;
    inorder(mp[A].second);
}

void postorder(char A){
    if(A=='.') return;
    postorder(mp[A].first);
    postorder(mp[A].second);
    cout<<A;
}


int main(void){
    cin.tie(NULL);
    ios::sync_with_stdio(false);

    cin>>n;
    char parent,left,right;
    for(int i=0;i<n;i++){
        cin>>parent>>left>>right;
        mp[parent] = pr(left,right);
    }
    //전,중,후 pre in post
    preorder('A');
    cout<<"\n";
    inorder('A');
    cout<<"\n";
    postorder('A');
    cout<<"\n";
}