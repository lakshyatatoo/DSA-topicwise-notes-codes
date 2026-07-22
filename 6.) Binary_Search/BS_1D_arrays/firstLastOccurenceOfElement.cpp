#include <bits/stdc++.h>
using namespace std;

// brutte loop on
// int first=-1, last=-1;
// class Solution {
//   public:
//     vector<int> searchRange(vector<int>& nums, int target) {
//         int n=nums.size();
//         for(int i=0;i<n;i++){
//             if(nums[i]==target){
//                 if(first==-1) first=i;
//                 last=i;
//             }
//         }
//         return {first,last};
//     }
// };

// // upper and lower bound approach
// class Solution
// {
// public:
//     int lowerbound(vector<int> &arr, int x)
//     { // first occurernce

//         int n = arr.size();
//         int ans = n;
//         int l = 0;
//         int h = n - 1;
//         while (l <= h)
//         {
//             int mid = (l + h) / 2;
//             if (arr[mid] >= x)
//             {
//                 ans = mid;
//                 h = mid - 1;
//             }
//             else
//             {
//                 l = mid + 1;
//             }
//         }
//         return ans;
//     }
//     int upperbound(vector<int> &arr, int x)
//     { // last occurence
//         // code here
//         int n = arr.size();
//         int ans = n;
//         int l = 0;
//         int h = n - 1;
//         while (l <= h)
//         {
//             int mid = (l + h) / 2;
//             if (arr[mid] > x)
//             {
//                 ans = mid;
//                 h = mid - 1;
//             }
//             else
//             {
//                 l = mid + 1;
//             }
//         }
//         return ans;
//     }

// public:
//     vector<int> searchRange(vector<int> &nums, int target)
//     {
//         int n = nums.size();
//         int lb = lowerbound(nums, target);
//         if (lb == n || target != nums[lb])
//             return {-1, -1};
//         else
//             return {lb, (upperbound(nums, target)) - 1};
//     }
// };

// //binary search approach
// class Solution {
//     public:
//     int firstocr(vector<int>& nums, int target,int n) {
//          int low=0;
//          int high=n-1;
//          int first=-1;
//          while(low<=high){
//              int mid=(low+high)/2;

//             if(target==nums[mid]) {first=mid;high=mid-1;}
//             else if(target>nums[mid]) low=mid+1;
//             else high=mid-1;
//         }
//         return first;
//     }

// int lastocr(vector<int>& nums, int target,int n) {
//          int low=0;
//          int high=n-1;
//          int last=-1;
//          while(low<=high){
//              int mid=(low+high)/2;

//             if(target==nums[mid]) {last=mid;low=mid+1;}
//             else if(target>nums[mid]) low=mid+1;
//             else high=mid-1;
//         }
//         return last;
//     }

// public:
//     vector<int> searchRange(vector<int>& nums, int target) {
//         int n=nums.size();
//         int first=firstocr(nums,target,n);
//         if(first==-1) return {-1,-1};
//         return {first,lastocr(nums,target,n)};
//     }
// };



