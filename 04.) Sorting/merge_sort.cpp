#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    // Merge two sorted halves
    void merge(vector<int> &arr, int low, int mid, int high)
    {
        vector<int> temp;
        int left = low, right = mid + 1;

        while (left <= mid && right <= high)
        {
            if (arr[left] <= arr[right])
                temp.push_back(arr[left++]);
            else
                temp.push_back(arr[right++]);
        }
        while (left <= mid)
            temp.push_back(arr[left++]);
        while (right <= high)
            temp.push_back(arr[right++]);

        // Copy sorted elements back into arr
        for (int i = low; i <= high; i++)
            arr[i] = temp[i - low];
    }

    // Merge Sort
    void mergeSort(vector<int> &arr, int low, int high)
    {
        // Base case
        if (low >= high)
            return;

        int mid = (low + high) / 2;
        mergeSort(arr, low, mid);
        mergeSort(arr, mid + 1, high);
        merge(arr, low, mid, high);
    }
};