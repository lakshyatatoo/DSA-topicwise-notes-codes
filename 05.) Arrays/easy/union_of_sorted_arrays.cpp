#include <bits/stdc++.h>
using namespace std;

// ============================================================
// Brute Force
// ============================================================
// Idea:
// Use a set to store all elements from both arrays.
// A set automatically:
// 1. Removes duplicates
// 2. Keeps elements sorted
//
// TC: O((n1 + n2) log(n1 + n2))
// SC: O(n1 + n2)

class Solution
{
public:
    vector<int> findUnion(vector<int> &a, vector<int> &b)
    {
        set<int> st;

        // Insert elements of a
        for (int i = 0; i < a.size(); i++)
            st.insert(a[i]);

        // Insert elements of b
        for (int i = 0; i < b.size(); i++)
            st.insert(b[i]);

        // Copy set into result
        vector<int> ans;
        for (auto it : st)
            ans.push_back(it);

        return ans;
    }
};

// ============================================================
// Optimal — Two Pointers
// ============================================================
// Assumption:
// Both arrays are already sorted.
//
// Idea:
// Use two pointers:
// i -> array a
// j -> array b
//
// Compare a[i] and b[j].
// Take the smaller element and move that pointer.
// If equal, take it only once and move both.
//
// ans.back() is used to avoid duplicates.
//
// TC: O(n1 + n2)
// SC: O(n1 + n2) for the output vector
//
// Extra auxiliary space: O(1)
// ============================================================

class Solution
{
public:
    vector<int> findUnion(vector<int> &a, vector<int> &b)
    {
        int n = a.size(), m = b.size(), i = 0, j = 0;
        vector<int> ans;
        while (i < n && j < m)
        {
            if (a[i] <= b[j])
            {
                if (ans.empty() || ans.back() != a[i])
                    ans.push_back(a[i]);
                i++;
            }
            else
            {
                if (ans.empty() || ans.back() != b[j])
                    ans.push_back(b[j]);
                j++;
            }
        }
        while (i < n)
        {
            if (ans.empty() || ans.back() != a[i])
                ans.push_back(a[i]);
            i++;
        }
        while (j < m)
        {
            if (ans.empty() || ans.back() != b[j])
                ans.push_back(b[j]);
            j++;
        }
        return ans;
    }
};