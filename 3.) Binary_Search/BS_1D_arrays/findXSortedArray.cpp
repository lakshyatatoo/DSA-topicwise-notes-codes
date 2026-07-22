#include <bits/stdc++.h>
using namespace std;

// iterative approach
//  class Solution {
//  public:
//  int search(vector<int>& nums, int target) {
//      int low=0;
//      int n=nums.size();
//      int high=n-1;
//      while(low<=high){
//          int mid=(low+high)/2;

//         if(target==nums[mid]) return mid;
//         else if(target>nums[mid]) low=mid+1;
//         else high=mid-1;
//     }
//     return -1;
// }
// };

// // recursive approach
// class Solution {
// public:
//     int binary_search(vector<int>& nums, int target, int low, int high) {
//         if (low > high)
//             return -1;
//         int mid = (low + high) / 2;
//         if (nums[mid] == target)
//             return mid;
//         else if (target > nums[mid])
//             return binary_search(nums, target, mid + 1, high);
//         else {
//             return binary_search(nums, target, low, mid - 1);
//         }
//     }

//     int search(vector<int>& nums, int target) {
//         int n = nums.size();
//         int low = 0;
//         int high = n - 1;
//         return binary_search(nums, target, low, high);
//     };
// };


#include <bits/stdc++.h>
using namespace std;


int binarysearchrecursievapproch(vector<int> &arr, int low,int high,int target){
    if(low>high){
        return -1;
    }
    int mid=low+(high-low)/2;
    if(arr[mid]==target){
        return mid;
    }
    else if(arr[mid]>target){
        return binarysearchrecursievapproch(arr,low,mid-1,target);
    }
    else {
        return binarysearchrecursievapproch(arr,mid+1,high,target);
    }
}