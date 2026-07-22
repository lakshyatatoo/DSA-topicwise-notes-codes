#include <bits/stdc++.h>
using namespace std;

// // brute merge in 3rd arrat and find
class Solution
{
public:
    double findMedianSortedArrays(vector<int> &nums1, vector<int> &nums2)
    {
        int n1 = nums1.size();
        int n2 = nums2.size();
        int n = n1 + n2;
        vector<int> v;
        int i = 0, j = 0;
        while (i < n1 && j < n2)
        {
            if (nums1[i] < nums2[j])
            {
                v.push_back(nums1[i++]);
            }
            else
            {
                v.push_back(nums2[j++]);
            }
        }
        while (i < n1)
        {
            v.push_back(nums1[i++]);
        }
        while (j < n2)
        {
            v.push_back(nums2[j++]);
        }

        if (n % 2 == 0)
        {
            return (double)((double)v[n / 2] + (double)v[n / 2 - 1]) / 2.0;
        }
        return v[n / 2];
    }
};

// // better approach - no extra space
class Solution
{
public:
    double findMedianSortedArrays(vector<int> &nums1, vector<int> &nums2)
    {
        int size1 = nums1.size();
        int size2 = nums2.size();
        int totalSize = size1 + size2;

        int i = 0, j = 0;
        int leftIndex = (totalSize / 2) - 1;
        int rightIndex = totalSize / 2;

        int leftMedian = -1, rightMedian = -1;
        int currIndexMergedOrder = 0;

        while (i < size1 && j < size2)
        {
            if (nums1[i] < nums2[j])
            {
                if (currIndexMergedOrder == leftIndex)
                    leftMedian = nums1[i];
                if (currIndexMergedOrder == rightIndex)
                    rightMedian = nums1[i];

                i++;
            }
            else
            {
                if (currIndexMergedOrder == leftIndex)
                    leftMedian = nums2[j];
                if (currIndexMergedOrder == rightIndex)
                    rightMedian = nums2[j];

                j++;
            }
            currIndexMergedOrder++;
        }

        while (i < size1)
        {
            if (currIndexMergedOrder == leftIndex)
                leftMedian = nums1[i];
            if (currIndexMergedOrder == rightIndex)
            {
                rightMedian = nums1[i];
                break;
            }
            i++;
            currIndexMergedOrder++;
        }

        while (j < size2)
        {
            if (currIndexMergedOrder == leftIndex)
                leftMedian = nums2[j];
            if (currIndexMergedOrder == rightIndex)
            {
                rightMedian = nums2[j];
                break;
            }
            j++;
            currIndexMergedOrder++;
        }

        if (totalSize % 2 == 0)
            return (leftMedian + rightMedian) / 2.0;

        return (double)rightMedian;
    }
};

// binary search
class Solution
{
public:
    double findMedianSortedArrays(vector<int> &nums1, vector<int> &nums2)
    {
        int n1 = nums1.size();
        int n2 = nums2.size();
        if (n1 > n2)
            return findMedianSortedArrays(nums2, nums1);
        int low = 0, high = n1, left = (n1 + n2 + 1) / 2, n = n1 + n2;
        while (low <= high)
        {
            int mid1 = (low + high) / 2;
            int mid2 = left - mid1;
            int l1 = INT_MIN, l2 = INT_MIN, r1 = INT_MAX, r2 = INT_MAX;
            if (mid1 < n1)
                r1 = nums1[mid1];
            if (mid2 < n2)
                r2 = nums2[mid2];
            if (mid1 - 1 >= 0)
                l1 = nums1[mid1 - 1];
            if (mid2 - 1 >= 0)
                l2 = nums2[mid2 - 1];

            if (l1 <= r2 && l2 <= r1)
            {
                if (n % 2 == 0)
                    return ((double)(max(l1, l2) + (double)min(r1, r2))) / 2.0;
                return (double)max(l1, l2);
            }
            else if (l1 > r2)
                high = mid1 - 1;
            else
                low = mid1 + 1;
        }
        return 0.0;
    }
};