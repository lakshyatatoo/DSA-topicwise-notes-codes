class Solution
{
public:
    void insertionSortRecursion(vector<int> &arr, int n)
    {
        if (n <= 1)
            return;
        insertionSortRecursion(arr, n - 1);

        int last = arr[n - 1];
        int j = n - 2;

        while (j >= 0 && arr[j] > last)
        {
            arr[j + 1] = arr[j];
            j--;
        }
        arr[j + 1] = last;
    }

    void insertionSort(vector<int> &arr)
    {
        int n = arr.size();

        insertionSortRecursion(arr, n);
        // code here
    }
};