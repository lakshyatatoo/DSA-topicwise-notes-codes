#include <bits/stdc++.h>
using namespace std;
// //brute tle
// class Solution {
//   public:
//     int maxLength(vector<int>& arr) {
//         // code here
//         int n=arr.size();
//         int sum=0;
//         int maxi=0;
//         for(int i=0;i<n;i++){
//             for(int j=i;j<n;j++){
//                 sum=0;
//                 for(int k=i;k<=j;k++){
//                     sum+=arr[k];
//                 }
//                 if(sum==0){
//                     maxi=max(maxi,j-i+1);
//                 }
//             }
//         }
//         return maxi;
//     }
// };

// //better. tle
// class Solution {
//   public:
//     int maxLength(vector<int>& arr) {
//         // code here
//         int n=arr.size();
//         int sum=0;
//         int maxi=0;
//         for(int i=0;i<n;i++){
//             sum=0;
//             for(int j=i;j<n;j++){

//                 sum+=arr[j];
//                 if(sum==0){
//                     maxi=max(maxi,j-i+1);
//                 }
//             }
//         }
//         return maxi;
//     }
// };

// // optimal
// class Solution
// {
// public:
//     int maxLength(vector<int> &arr)
//     {
//         // code here
//         int n = arr.size();
//         int sum = 0;
//         int maxi = 0;
//         unordered_map<int, int> mp;
//         for (int i = 0; i < n; i++)
//         {
//             sum += arr[i];
//             if (sum == 0)
//             {
//                 maxi = i + 1;
//             }

//             else
//             {
//                 if (mp.find(sum) != mp.end())
//                 {
//                     maxi = max(maxi, i - mp[sum]);
//                 }
//                 else
//                 {
//                     mp[sum] = i;
//                 }
//             }
//         }
//         return maxi;
//     }
// };