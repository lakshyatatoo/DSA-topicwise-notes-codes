#include <bits/stdc++.h>
using namespace std;

// //search for insert position of x in sorted array
// //basically lower bound\
// class Solution {
//   public:
//     int searchInsert(vector<int>& arr, int x) {
//         // code here
//         int n=arr.size();
//         int ans=n;
//         int l=0;
//         int h=n-1;
//         while(l<=h){
//             int mid=(l+h)/2;
//             if(arr[mid]>=x){
//                 ans=mid;
//                 h=mid-1;
//             }
//             else {
//                 l=mid+1;
//             }
//         }
//         return ans;
//     }
// };

// //floor and ceil of x in sorted array

// class Solution {
//     public:
//     int flr(vector<int>& arr, int x) {
//         // code here
//         int n=arr.size();
//         int ans=-1;
//         int l=0;
//         int h=n-1;
//         while(l<=h){
//             int mid=(l+h)/2;
//             if(arr[mid]<=x){
//                 ans=arr[mid];
//                 l=mid+1;
//             }
//             else {
//                 h=mid-1;
//             }
//         }
//         return ans;
//     }
//     int cil(vector<int>& arr, int x) {
//         // code here
//         int n=arr.size();
//         int ans=-1;
//         int l=0;
//         int h=n-1;
//         while(l<=h){
//             int mid=(l+h)/2;
//             if(arr[mid]>=x){
//                 ans=arr[mid];
//                 h=mid-1;
//             }
//             else {
//                 l=mid+1;
//             }
//         }
//         return ans;
//     }
//   public:
//     vector<int> getFloorAndCeil(int x, vector<int> &arr) {
//         // code here
//         sort(arr.begin(),arr.end());
//         int floor=flr(arr,x);
//         int ceil=cil(arr,x);
//          return {floor, ceil};

//     }
// };
