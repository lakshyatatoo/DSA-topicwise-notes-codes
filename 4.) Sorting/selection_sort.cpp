#include <bits/stdc++.h>
using namespace std;
int main()
{
    int n;
    cin >> n;
    int arr[n];
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }
    for (int i = 0; i <= n - 2; i++)
    {
        int mini = i;
        for (int j = i; j <= n - 1; j++)
        {
            if (arr[j] < arr[mini])
            {
                mini = j;
            }
        }
        swap(arr[i], arr[mini]);
        // using temp;
    }
    for (int i = 0; i < n; i++)
    {
        cout << arr[i] << " ";
    }
    cout << endl;
}

//
// gfg selection sort
class Solution
{
public:
    // Function to perform selection sort on the given array.
    void selectionSort(vector<int> &arr)
    {
        // code here
        int n = arr.size();
        for (int i = 0; i < n - 1; i++)
        {
            int mini = i;
            for (int j = i; j < n; j++)
            {
                if (arr[j] < arr[mini])
                {
                    mini = j;
                }
            }
            swap(arr[i], arr[mini]);
            // using temp;
        }
    }
};