#include <bits/stdc++.h>
using namespace std;

// binary search to find x in sorted array
class Solution
{
public:
    int findKRotation(vector<int> &nums)
    {
        {
            int n = nums.size();
            int low = 0;
            int high = n - 1;
            int ans = INT_MAX;
            int indexi = INT_MAX;
            while (low <= high)
            {
                int mid = (low + high) / 2;

                // if array is already sorted
                // reduces time complexity
                if (nums[low] <= nums[high])
                {
                    if (nums[low] < ans)
                    {
                        indexi = low;
                        ans = nums[low];
                    }
                    break;
                }

                if (nums[low] <= nums[mid])
                {
                    if (nums[low] < ans)
                    {
                        indexi = low;
                        ans = nums[low];
                    }

                    low = mid + 1;
                }
                else
                {
                    if (nums[mid] < ans)
                    {
                        indexi = mid;
                        ans = nums[mid];
                    }
                    high = mid - 1;
                }
            }
            return indexi;
        }
    }
};
