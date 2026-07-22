// //brute(nested loops)
// class Solution {
// public:
//     int singleNumber(vector<int>& nums) {
//        int n=nums.size();
//        int target=0;
//        int cnt=0;
//        for(int i=0;i<n;i++){
//             target=nums[i];
//             cnt=0;
//             for(int j=0;j<n;j++){
//                 if(nums[j]==target){
//                     cnt++;
//                 }
//             }
//             if(cnt==1){
//                 return target;
//             }
//        }
//        return -1;
//     }
// };

// //better
// //hash array for positive numbersclass Solution {
// public:
//     int singleNumber(vector<int>& nums) {
//         int maxi=0;
//         for(int x:nums){
//             maxi=max(x,maxi);
//         }
//         vector<int> hsh(maxi+1,0);
//         for(int x:nums){
//             hsh[x]++;
//         }
//         for(int i=0;i<hsh.size();i++){
//             if (hsh[i]==1){
//                 return i;
//             }
//         }
//         return -1;
//     }
// };

// //unordered map for both positive and negative numbers
// class Solution {
// public:
//     int singleNumber(vector<int>& nums) {
//         unordered_map<long long,int> freq;
//         for(int x:nums){
//             freq[x]++;
//         }
//         for(auto &pair : freq){
//             if (pair.second==1){
//                 return pair.first;
//             }
//         }
//         return -1;
//     }
// };

// //optimal(using bit manipulation(XOR))
// class Solution {
// public:
//     int singleNumber(vector<int>& nums) {
//         int xory=0;
//         for(int x:nums){
//             xory=xory^x;
//         }
//         return xory;
//     }
// };
