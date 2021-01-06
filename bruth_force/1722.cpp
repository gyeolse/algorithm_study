#include <bits/stdc++.h>
using namespace std;



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