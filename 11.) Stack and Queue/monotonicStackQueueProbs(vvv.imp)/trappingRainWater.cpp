#include <bits/stdc++.h>
using namespace std;

// brute
// tc:O(n) sc:O(n)
class Solution
{
public:
    int trap(vector<int> &height)
    {
        int n = height.size();
        vector<int> ml(n);
        vector<int> mr(n);
        vector<int> mb(n);
        int maxl = 0;
        int maxr = 0;
        for (int i = 0; i < n; i++)
        {
            ml[i] = maxl;
            if (height[i] > maxl)
                maxl = height[i];
        }
        for (int i = n - 1; i >= 0; i--)
        {
            mr[i] = maxr;
            if (height[i] > maxr)
                maxr = height[i];
        }
        int quantity = 0;
        for (int i = 0; i < n; i++)
        {
            mb[i] = min(ml[i], mr[i]);
            if (mb[i] - height[i] >= 0)
            {
                quantity += mb[i] - height[i];
            }
        }
        return quantity;
    }
};

// better is maintaining only suffix or prefix array and calculating the other on the fly

// optimal
// tc:O(n) sc:O(1)
int trap(vector<int> &height)
{
    int n = height.size(), l = 0, r = n - 1, leftMax = height[0],
        rightMax = height[n - 1], q = 0;
    while (l < r)
    {
        if (leftMax < rightMax)
        {
            l++;
            leftMax = max(leftMax, height[l]);
            q += leftMax - height[l];
        }
        else
        {
            r--;
            rightMax = max(rightMax, height[r]);
            q += rightMax - height[r];
        }
    }
    return q;
}

// optimal too
int trap(vector<int> &height)
{
    int n = height.size(), l = 0, r = n - 1, leftMax = 0,
        rightMax = 0, q = 0;
    while (l < r)
    {
        if (height[l] <= height[r])
        {
            if (leftMax > height[l])
                q += leftMax - height[l];
            else
                leftMax = height[l];
            l++;
        }
        else
        {
            if (rightMax > height[r])
                q += rightMax - height[r];
            else
                rightMax = height[r];
            r--;
        }
    }
    return q;
}