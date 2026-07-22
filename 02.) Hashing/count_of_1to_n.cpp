// class Solution {
//   public:
//     // Function to count the frequency of all elements from 1 to N in the array.
//     vector<int> frequencyCount(vector<int>& arr) {//storing occurences of each element in 1 less
//        
//         int n=arr.size();
//         vector<int> hash(n,0);
//         for(int i=0;i<n;i++){
//             hash[arr[i]-1]++;

//         }
//         return hash;
//     }
// };
