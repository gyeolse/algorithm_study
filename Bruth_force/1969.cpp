#include <bits/stdc++.h>
#define endl '\n'
using namespace std;

int cnt[51][4]; //A C G T 순

int n, m;

int main() {
    cin.tie(NULL); ios::sync_with_stdio(false);
    cin >> n >> m;

    //input에 맞게, 각 자리수에서의 알파벳 카운트, 
    for (int i = 0;i < n;i++) {
        string s; cin >> s;

        for(int j=0;j<s.size();j++) {
            if(s[j] == 'A') {
                cnt[j][0]++;
            }
            else if(s[j]=='C') {
                cnt[j][1]++;
            }
            else if(s[j]=='G') {
                cnt[j][2]++;
            }
            else {
                cnt[j][3]++;
            }
        }
    }
    
    string ans="";
    int res=0;
    for(int i=0;i<m;i++) {
        int temp = *max_element(cnt[i],cnt[i]+4);
        int dist = 0;
        if(cnt[i][0] == temp) {
            dist = cnt[i][1] + cnt[i][2] + cnt[i][3];
            ans += 'A';
        }
        else if (cnt[i][1] == temp) {
            dist = cnt[i][0] + cnt[i][2] + cnt[i][3];            
            ans += 'C';
        }
        else if(cnt[i][2] == temp) {
            dist = cnt[i][1] + cnt[i][3] + cnt[i][0];            
            ans += 'G';
        }
        else {
            dist = cnt[i][1] + cnt[i][2] + cnt[i][0];            
            ans += 'T';
        }

        res+=dist;
    }


    cout<<ans<<endl;
    cout<<res<<endl;
    return 0;
}