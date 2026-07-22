#include <bits/stdc++.h>
using namespace std;
//or we can just return low
// //lower bound
class Solution
{
public:
    int lowerbound(vector<int> &arr, int x)
    {
        // code here
        int n = arr.size();
        int ans = n;
        int l = 0;
        int h = n - 1;
        while (l <= h)
        {
            int mid = (l + h) / 2;
            if (arr[mid] >= x)
            {
                ans = mid;
                h = mid - 1;
            }
            else
            {
                l = mid + 1;
            }
        }
        return ans;
    }
};

// //upper bound
// change in if consditon
// // >= to >
// class Solution {
//   public:
// int upperbound(vector<int>& arr, int x) {
//     // code here
//     int n=arr.size();
//     int ans=n;
//     int l=0;
//     int h=n-1;
//     while(l<=h){
//         int mid=(l+h)/2;
//         if(arr[mid]>x){
//             ans=mid;
//             h=mid-1;
//         }
//         else {
//             l=mid+1;
//         }
//     }
//     return ans;
// }
// };