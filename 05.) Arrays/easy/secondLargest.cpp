// // brute
// class Solution
// {
// public:
//     int getSecondLargest(vector<int> &arr)
//     {
//         int n = arr.size();

//         sort(arr.begin(), arr.end());
//         int le = arr[n - 1];
//         int sle = -1;
//         for (int i = n - 2; i >= 0; i--)
//         {
//             if (arr[i] != le)
//             {
//                 sle = arr[i];
//                 break;
//             }
//         }
//         return sle;
//     }
// };

// // better
// class Solution
// {
// public:
//     int getSecondLargest(vector<int> &arr)
//     {
//         int n = arr.size();
//         int largest = a[0];
//         for (int i = 0; i < n; i++)
//         {
//             if (arr[i] > largest)
//             {
//                 largest = arr[i];
//             }
//         }

//         int sLargest = -1;
//         for (int i = 0; i < n; i++)
//         {
//             if (arr[i] > sLargest && arr[i] != 0)
//             {
//                 arr[i] = sLargest;
//             }
//         }

//         return sLargest;
//     }
// };

// // optimal
// class Solution
// {
// public:
//     int getSecondLargest(vector<int> &arr)//optimal
//     {
//         int n = arr.size();

//         int largest = arr[0];
//         int sLargest = -1;
//         for (int i = 0; i < n; i++)
//         {
//             if (arr[i] > largest)
//             {
//                 sLargest = largest;
//                 largest = arr[i];
//             }
//             else if(arr[i]>sLargest && arr[i]!=largest){
//                 sLargest=arr[i];
//             }
//         }

//         return sLargest;
//     }
// };