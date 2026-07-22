#include <bits/stdc++.h>
using namespace std;

// //brute tle 3 loops
// class Solution {
//   public:
//     long subarrayXor(vector<int> &arr, int k) {
//         int n=arr.size();
//         int cnt=0;
//         int xr=0;
//         for(int i=0;i<n;i++){
//             for(int j=i;j<n;j++){
//                 xr=0;
//                 for(int k=i;k<=j;k++){
//                     xr=xr^arr[k];
//                 }
//                 if(xr==k){
//                     cnt++;
//                 }

//             }
//         }
//         return cnt;
//     }
// };

// // better 2 loops tle
// class Solution
// {
// public:
//     long subarrayXor(vector<int> &arr, int k)
//     {
//         int n = arr.size();
//         int cnt = 0;
//         int xr = 0;
//         for (int i = 0; i < n; i++)
//         {
//             xr = 0;
//             for (int j = i; j < n; j++)
//             {

//                 xr = xr ^ arr[j];

//                 if (xr == k)
//                 {
//                     cnt++;
//                 }
//             }
//         }
//         return cnt;
//     }
// };

// //optimal
// class Solution
// {
// public:
//     long subarrayXor(vector<int> &arr, int k)
//     {
//         int n = arr.size();
//         int cnt = 0;
//         unordered_map<int, int> mp;
//         int xr = 0;
//         mp[0] = 1; // for the case when prefix itself is equal to k
//         for (int i = 0; i < n; i++)
//         {
//             xr = xr ^ arr[i];
//             int x = xr ^ k;
//             cnt+=mp[x];
//             mp[xr]++;
//         }
//         return cnt;
//     }
// };