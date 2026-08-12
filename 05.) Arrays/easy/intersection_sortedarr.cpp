#include <bits/stdc++.h>
using namespace std;

// ============================================================
// Intersection of Two Sorted Arrays
// ============================================================
// Assumption:
// Both arrays are sorted.
//
// Idea:
// Use two pointers:
//
// i -> points to current element of a
// j -> points to current element of b
//
// If a[i] < b[j]:
//     Move i because a[i] cannot be a match.
//
// If b[j] < a[i]:
//     Move j because b[j] cannot be a match.
//
// If a[i] == b[j]:
//     We found a common element.
//     Add it to the answer and move both pointers.
//
// ans.back() prevents duplicate elements.
//
// TC: O(n + m)
// SC: O(min(n, m)) for the output
// ============================================================

class Solution
{
public:
    vector<int> intersection(vector<int> &a, vector<int> &b)
    {
        int n = a.size();
        int m = b.size();

        int i = 0;
        int j = 0;

        vector<int> ans;

        while (i < n && j < m)
        {
            if (a[i] < b[j])
            {
                i++;
            }
            else if (b[j] < a[i])
            {
                j++;
            }
            else
            {
                // a[i] == b[j]
                if (ans.empty() || ans.back() != a[i])
                {
                    ans.push_back(a[i]);
                }

                i++;
                j++;
            }
        }

        return ans;
    }
};