// Quick Sort Implementation
#include <bits/stdc++.h>
using namespace std;

// Ascending order
class SolutionAscending
{
public:
    void quickSort(vector<int> &arr, int low, int high)
    {
        if (low < high)
        {
            int pivotFind = partition(arr, low, high);
            quickSort(arr, low, pivotFind - 1);
            quickSort(arr, pivotFind + 1, high);
        }
    }

    int partition(vector<int> &arr, int low, int high)
    {
        int pivot = arr[low];
        int i = low;
        int j = high;
        while (i < j)
        {
            while (i <= high - 1 && arr[i] <= pivot)
            {
                i++;
            }
            while (j >= low + 1 && arr[j] > pivot)
            {
                j--;
            }
            if (i < j)
            {
                swap(arr[i], arr[j]);
            }
        }
        swap(arr[j], arr[low]);
        return j;
    }
};

// Descending order
class SolutionDescending
{
public:
    void quickSort(vector<int> &arr, int low, int high)
    {
        if (low < high)
        {
            int pivotFind = partition(arr, low, high);
            quickSort(arr, low, pivotFind - 1);
            quickSort(arr, pivotFind + 1, high);
        }
    }

    int partition(vector<int> &arr, int low, int high)
    {
        int pivot = arr[low];
        int i = low;
        int j = high;
        while (i < j)
        {
            while (i <= high - 1 && arr[i] > pivot)
            {
                i++;
            }
            while (j >= low + 1 && arr[j] <= pivot)
            {
                j--;
            }
            if (i < j)
            {
                swap(arr[i], arr[j]);
            }
        }
        swap(arr[j], arr[low]);
        return j;
    }
};
