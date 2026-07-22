#include <bits/stdc++.h>
using namespace std;

// // binary search
// class Solution
// {
// public:
//     int firstocr(vector<int> &nums, int target, int n)
//     {
//         int low = 0;
//         int high = n - 1;
//         int first = -1;
//         while (low <= high)
//         {
//             int mid = (low + high) / 2;

//             if (target == nums[mid])
//             {
//                 first = mid;
//                 high = mid - 1;
//             }
//             else if (target > nums[mid])
//                 low = mid + 1;
//             else
//                 high = mid - 1;
//         }
//         return first;
//     }

//     int lastocr(vector<int> &nums, int target, int n)
//     {
//         int low = 0;
//         int high = n - 1;
//         int last = -1;
//         while (low <= high)
//         {
//             int mid = (low + high) / 2;

//             if (target == nums[mid])
//             {
//                 last = mid;
//                 low = mid + 1;
//             }
//             else if (target > nums[mid])
//                 low = mid + 1;
//             else
//                 high = mid - 1;
//         }
//         return last;
//     }

// public:
//     int countFreq(vector<int> &nums, int target)
//     {
//         int n = nums.size();
//         int first = firstocr(nums, target, n);
//         int last = lastocr(nums, target, n);
//         if (first == -1)
//             return 0;
//         return (last - first + 1);
//     }
// };