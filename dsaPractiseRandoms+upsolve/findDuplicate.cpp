#include <bits/stdc++.h>
using namespace std;

// brute force approach
// tc O(n^2) sc O(1)

// better approach
// tc O(n) sc O(n). //hashing

// optimal approach
// tc O(n) sc O(1)
// since number are in range 1 to n, we can say each index element points to a index inside the array,
// ex [1,3,4,2,2]index[0,1,2,3,4] 0-1,1-3,2-4,3-2,4-2
// we can mark the visited index as negative, if we find a index which is already negative then we can say that the number is repeated
class Solution
{
public:
    int findDuplicate(vector<int> &nums)
    {
        int n = nums.size();
        int slow = 0, fast = 0;
        while (true)
        {
            slow = nums[slow];
            fast = nums[nums[fast]];
            if (slow == fast)
                break;
        }
        int slow = 0;
        while (slow != fast)
        {
            slow = nums[slow];
            fast = nums[fast];
        }
        return slow;
    }
};