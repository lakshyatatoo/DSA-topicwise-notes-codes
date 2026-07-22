#include <bits/stdc++.h>
using namespace std;

// binary search plus a extra condition to handle duplicates
class Solution
{
public:
    bool search(vector<int> &nums, int target)
    {
        {
            int n = nums.size();
            int low = 0;
            int high = n - 1;
            while (low <= high)
            {
                int mid = (low + high) / 2;
                if (target == nums[mid])
                    return true;
                if (nums[low] == nums[mid] && nums[mid] == nums[high])
                {
                    low++;
                    high--;
                    continue; // if maybe new shrink space also does this condition so we skip this shi
                    // and mid gets recalculated
                }

                if (nums[low] <= nums[mid])
                {
                    if (nums[low] <= target && target <= nums[mid])
                    {
                        high = mid - 1;
                    }
                    else
                    {
                        low = mid + 1;
                    }
                }
                else
                {
                    if (nums[mid] <= target && target <= nums[high])
                    {
                        low = mid + 1;
                    }
                    else
                    {
                        high = mid - 1;
                    }
                }
            }
            return false;
        }
    }
};