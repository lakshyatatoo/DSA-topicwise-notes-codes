#include <bits/stdc++.h>
using namespace std;
class Solution
{
public:
    void bubbleSort(vector<int> &arr)
    {

        bubbleSortRecursion(arr, arr.size() - 1);
    }

    void bubbleSortRecursion(vector<int> &arr, int n)
    {
        // code here

        if (n <= 0)
            return;

        bool didSwap = false; // if no swap is done it will break out for optimal

        for (int j = 0; j < n; j++)
        {
            if (arr[j] > arr[j + 1])
            {
                swap(arr[j], arr[j + 1]);
                didSwap = true;
            }
        }
        if (!didSwap)
            return;

        bubbleSortRecursion(arr, n - 1);
    }
};
int main()
{
}
