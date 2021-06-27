#include <bits/stdc++.h>
using namespace std;

bool chk[21]; //최대 21
long long factorial[21]; //팩토리얼 값 저장

void init() {
    factorial[0] = 1;
    for (int i = 1;i < 21;i++) {
        factorial[i] = factorial[i - 1] * i;
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    init();

    int n;
    int sel; //select

    cin >> n;
    cin >> sel;

    if(sel==1){
        long long k;
        cin>>k; //k를 입력받음
        vector<int>vec(n);
        
        for(int i=0;i<n;i++){
            for(int j=1;j<=n;j++) {
                if(chk[j]) {
                    continue;
                }
                if(k > factorial[n-i-1]) {
                    k-=factorial[n-i-1];
                } else {
                    vec[i] = j;
                    chk[j] = true;
                    break;
                }
            }
        }

        for(int i=0;i<n;i++){
            cout<< vec[i]<<" ";
        }

    } else {
        vector<int> vec(n);
        for(int i=0;i<n;i++) {
            cin>>vec[i];
        }
        long long result =0;
        for(int i=0;i<n;i++){
            for(int j=1;j<vec[i];j++){
                if(chk[j]) continue;
                result += factorial[n-1-i];
            }
            chk[vec[i]] = true;
        }

        cout<<result+1;
    }
    return 0;
}

// int main() {
//     ios::sync_with_stdio(false);
//     cin.tie(NULL);

//     int n;
//     int sel; //select

//     cin >> n;
//     vector<int> vec;
//     for (int i = 0;i < n;i++) { // O(n)
//         vec.push_back(i + 1);
//     }

//     cin >> sel;

//     if (sel == 1) { //1인 경우, 몇 번쨰 수열인지를 출력
//         int k;
//         cin >> k;

//         int cnt = 1;
//         do
//         {
//             if (cnt == k) {
//                 for (int i = 0;i < vec.size();i++) { // O(n^2) 이지만, cnt == k일때 뿐임. N! 이면 최대 20! 
//                     cout << vec[i] << " ";
//                 }
//             }
//             cnt++;
//         } while (next_permutation(vec.begin(), vec.end()));
//     }
//     else if (sel == 2) { //2인 경우, 수열을 입력받음 
//         vector <int> temp;
//         for (int i = 0;i < n;i++) {
//             int k;
//             cin>>k;
//             temp.push_back(k);
//         }
//         int cnt = 1;
//         do
//         {
//             if(temp==vec) cout<<cnt<<"\n";
//             cnt++;
//         } while (next_permutation(vec.begin(),vec.end()));


//     }

//     return 0;
// }