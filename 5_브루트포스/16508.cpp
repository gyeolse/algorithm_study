#include <bits/stdc++.h>
using namespace std;

#define INF 987654321

int n, cost; 
int res = INF;
int letter[26]; //단어의 빈도수가 저장되어있음. 
int cnt[26]; 
bool used[26];

pair<int, int[26]> book[16]; //가격이 first, 빈도수가 second

void func(int pos) {
    if(pos == n ) { //도달
        memset(cnt, 0, sizeof(cnt));
        for(int i=0;i<n;i++) {
            if(!used[i]) continue; //
            for(int j=0;j<26;j++) {
                cnt[j] += book[i].second[j];
            }
        }

        for(int i=0;i<26;i++) {
            if(cnt[i] < letter[i]) return; //책의 빈도수가 더 작으면 X
        }
        res = min(res,cost);
        return;
    }

    used[pos] = true; //사용
    cost += book[pos].first;
    func(pos+1); //사용한 상태서 input

    used[pos] = false;
    cost -= book[pos].first;
    func(pos+1);
}

int main() {

    string word, title;
    cin>>word>>n;

    for(int i=0;i<word.size();i++) {
        letter[word[i]-'A']++; //단어 빈도만큼 letter에 ++
    }

    for(int i=0;i<n;i++) {
        cin>>book[i].first>>title;
        for(int j=0;j<title.size();j++) {
            book[i].second[title[j]-'A']++; //단어 빈도수만큼 book의 두번째에 ++
        }
    }

    func(0);
    if(res == INF) cout<< -1<<endl;
    else cout<<res<<endl;
    return 0;
}
