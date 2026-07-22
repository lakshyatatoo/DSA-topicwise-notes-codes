// //brute
// class Solution {
// public:
//     int removeDuplicates(vector<int>& nums) {//brute
//         set<int> unq;//storing in set
//         int n=nums.size();
//         for(int i=0;i<n;i++){
//             unq.insert(nums[i]);
//         }

//         int index=0;
//         for(auto x:unq){
//             nums[index]=x;
//             index++;
//         }
//         return index;
//     }
// };

// //optimal
// class Solution {
// public:
//     int removeDuplicates(vector<int>& nums) {

//         int n=nums.size();
//         int i=0;
//         for(int j=1;j<n;j++){
//             if(nums[j]!=nums[i]){
//                 nums[i+1]=nums[j];
//                 i++;
//             }
//         }

//         return i+1;
//     }
// };