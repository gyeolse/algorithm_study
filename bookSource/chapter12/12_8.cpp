#include <iostream>
#include <algorithm>
#include <string>

using namespace std;
string n;
string n_res;
int res;

int main(void){
    cin>>n;
    for(int i=0;i<n.size();i++){
        sort(n.begin(),n.end());
    }

    for(int i=0;i<n.size();i++){
        if(n[i]>=48 && n[i]<=57){
            res += n[i]-'0';
        }
        else{
            n_res += n[i];
        }
    }
    n_res += to_string(res);
    cout<<n_res<<"\n";
    return 0;
}