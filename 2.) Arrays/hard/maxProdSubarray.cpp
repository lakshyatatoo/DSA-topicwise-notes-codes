#include <bits/stdc++.h>
using namespace std;

// // brute tle
// class Solution
// {
// public:
//     int maxProduct(vector<int> &nums)
//     {
//         int n = nums.size();
//         int prod = 1;
//         int prodmaxi = INT_MIN;
//         for (int i = 0; i < n; i++)
//         {
//             for (int j = i; j < n; j++)
//             {
//                 prod = 1;
//                 for (int k = i; k <= j; k++)
//                 {
//                     prod = prod * nums[k];
//                 }
//                 prodmaxi = max(prod, prodmaxi);
//             }
//         }
//         return prodmaxi;
//     }
// };

// // better clr
// class Solution
// {
// public:
//     int maxProduct(vector<int> &nums)
//     {
//         int n = nums.size();
//         int prod = 1;
//         int prodmaxi = INT_MIN;
//         for (int i = 0; i < n; i++)
//         {
//              prod = 1;
//             for (int j = i; j < n; j++)
//             {

//                 prod = prod * nums[j];
//                 prodmaxi = max(prod, prodmaxi);
//             }
//         }
//         return prodmaxi;
//     }
// };

//optimal 1 prefix and suffix
class Solution {
public:
    int maxProduct(vector<int>& nums) {
        int n=nums.size();
        long long pre=1,suff=1;
        long long ans=LLONG_MIN;
        for(int i=0;i<n;i++){
            if(pre==0) pre=1;
            if(suff==0) suff=1;

            pre*=nums[i];
            suff*=nums[n-i-1];
            ans=max(ans,max(pre,suff));
        }
        return ans;
    }
};

// optiaml 2 is kadance algo modification not advised
