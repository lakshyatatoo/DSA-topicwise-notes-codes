#include <bits/stdc++.h>
using namespace std;

// ============================================================
// 1. BRUTE FORCE
// An element is a leader if no element to its right is greater.
//
// Time: O(n^2)
// Space: O(n)
// ============================================================

class Solution
{
    // Function to find the leaders in the array.

public:
    vector<int> leaders(vector<int> &arr)
    {
        int leader = true;
        vector<int> ans;

        for (int i = 0; i < arr.size(); i++)
        {
            leader = true;

            for (int j = i + 1; j < arr.size(); j++)
            {
                if (arr[j] > arr[i])
                {
                    leader = false;
                    break;
                }
            }

            if (leader == true)
            {
                ans.push_back(arr[i]);
            }
        }

        return ans;
    }
};

// ============================================================
// 2. OPTIMAL — TRAVERSE FROM RIGHT
//
// Keep track of the maximum element seen so far.
// If arr[i] >= maxi, arr[i] is a leader.
//
// Time: O(n)
// Space: O(n)
// ============================================================

class Solution
{
    // Function to find the leaders in the array.

public:
    vector<int> leaders(vector<int> &arr)
    {
        int n = arr.size();

        int maxi = arr[n - 1];

        vector<int> ans;
        ans.push_back(maxi);

        for (int i = n - 2; i >= 0; i--)
        {
            if (arr[i] >= maxi)
            {
                ans.push_back(arr[i]);
                maxi = arr[i];
            }
        }

        reverse(ans.begin(), ans.end());

        return ans;
    }
};