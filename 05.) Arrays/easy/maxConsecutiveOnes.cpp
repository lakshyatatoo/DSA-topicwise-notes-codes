#include <bits/stdc++.h>
using namespace std;

// ============================================================
// Approach 1 — Index-based Loop
// ============================================================
// Idea:
// Keep counting consecutive 1s.
// When we encounter 0, reset the count to 0.
// Keep track of the maximum count.
//
// TC: O(n)
// SC: O(1)

class Solution
{
public:
    int findMaxConsecutiveOnes(vector<int> &nums)
    {
        int ones = 0;
        int ans = 0;

        for (int i = 0; i < nums.size(); i++)
        {
            if (nums[i] == 1)
            {
                ones++;
            }
            else
            {
                ones = 0;
            }

            ans = max(ans, ones);
        }

        return ans;
    }
};

// ============================================================
// Approach 2 — Range-based Loop
// ============================================================
// Idea:
// Same logic as above, but instead of using an index,
// directly iterate over each element.
//
// TC: O(n)
// SC: O(1)

class Solution
{
public:
    int findMaxConsecutiveOnes(vector<int> &nums)
    {
        int ones = 0;
        int ans = 0;

        for (auto x : nums)
        {
            if (x == 1)
            {
                ones++;
                ans = max(ans, ones);
            }
            else
            {
                ones = 0;
            }
        }

        return ans;
    }
};