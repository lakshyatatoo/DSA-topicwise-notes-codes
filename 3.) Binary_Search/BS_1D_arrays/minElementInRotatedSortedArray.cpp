#include <bits/stdc++.h>
using namespace std;

// linear search aslo can be done

// binary search to find min element in rotated sorted array
class Solution
{
public:
    int findMin(vector<int> &nums)
    {
        int n = nums.size();
        int low = 0;
        int high = n - 1;
        int ans = INT_MAX;
        while (low <= high)
        {
            int mid = (low + high) / 2;

            // if array is already sorted
            // reduces time complexity
            if (nums[low] <= nums[high])
            {
                ans = min(ans, nums[low]);
                break;
            }

            if (nums[low] <= nums[mid])
            {
                ans = min(ans, nums[low]);
                low = mid + 1;
            }
            else
            {
                ans = min(ans, nums[mid]);
                high = mid - 1;
            }
        }
        return ans;
    }
};