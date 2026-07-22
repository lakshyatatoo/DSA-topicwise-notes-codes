// // brute is sort and largest element
// class Solution {
//   public:
//     int largest(vector<int> &arr) {
//         // code here
//         int n=arr.size();

//         sort(arr.begin(),arr.end());

//         int le=arr[n-1];

//         return le;

//     }
// };

// // optimal
// class Solution
// {
// public:
//     int largest(vector<int> &arr)
//     {
//         // code here
//         int n = arr.size();
//         int maxim = arr[0];
//         for (int i = 0; i < n; i++)
//         {
//             if (arr[i] > maxim)
//             {
//                 maxim = arr[i]; // or use max function for maxim as 0
//             }
//         }
//         return maxim;
//     }
// };
