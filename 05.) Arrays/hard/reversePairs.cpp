#include <bits/stdc++.h>
using namespace std;

// //brute force approach tle
// //2 loops
class Solution
{
public:
    int reversePairs(vector<int> &nums)
    {
        int cnt = 0;
        int n = nums.size();
        for (int i = 0; i < n; i++)
        {
            for (int j = i + 1; j < n; j++)
            {
                long long x = nums[j];
                x = x * 2;
                if (nums[i] > x)
                    cnt++;
            }
        }
        return cnt;
    }
};

// notes in copy and revision will help you remember and understand this
// optimal merge sort approach
class Solution
{
public:
    void merge(vector<int> &arr, int low, int mid, int high)
    {
        vector<int> temp;
        int left = low;
        int right = mid + 1;

        while (left <= mid && right <= high)
        {
            if (arr[left] <= arr[right])
            {
                temp.push_back(arr[left]);
                left++;
            }
            else
            {
                temp.push_back(arr[right]);
                right++;
            }
        }
        while (left <= mid)
        {
            temp.push_back(arr[left]);
            left++;
        }
        while (right <= high)
        {
            temp.push_back(arr[right]);
            right++;
        }

        for (int i = low; i <= high; i++)
        {
            arr[i] = temp[i - low];
        }
    }
    int countPairs(vector<int> &arr, int low, int mid, int high)
    {
        int cnt = 0;
        int right = mid + 1;
        for (int i = low; i <= mid; i++)
        {
            while (right <= high && (long long)arr[i] > 2LL * arr[right])
            {
                right++;
            }

            cnt += (right - (mid + 1));
        }
        return cnt;
    }

public:
    int mergeSort(vector<int> &arr, int low, int high)
    {
        // code here
        int cnt = 0;
        if (low >= high)
            return cnt;

        int mid = (low + high) / 2;

        cnt += mergeSort(arr, low, mid);
        cnt += mergeSort(arr, mid + 1, high); // for each ms cntprs is called
        cnt += countPairs(arr, low, mid, high);
        merge(arr, low, mid, high);
        return cnt;
    }

public:
    int reversePairs(vector<int> &nums)
    {
        int n = nums.size();
        return mergeSort(nums, 0, n - 1);
    }
};