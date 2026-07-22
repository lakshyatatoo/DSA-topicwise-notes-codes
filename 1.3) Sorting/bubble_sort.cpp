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
    for (int i = n - 1; i >= 0; i--)
    {
        int didswap = 0; // if no swap is done it will break out for optimal

        for (int j = 0; j < i; j++)
        {
            if (arr[j] > arr[j + 1])
            {
                swap(arr[j], arr[j + 1]);
                didswap++;
            }
        }
        if (didswap == 0)
        {
            break;
        }
    }
    for (int i = 0; i < n; i++)
    {
        cout << arr[i] << " ";
    }
    cout << endl;
}

//
// gfg bubble sort
class Solution
{
public:
    void bubbleSort(vector<int> &arr)
    {
        // code here
        int n = arr.size();
        for (int i = n - 1; i >= 1; i--)
        {

            for (int j = 0; j < i; j++)
            {
                if (arr[j] > arr[j + 1])
                {
                    swap(arr[j], arr[j + 1]);
                }
            }
        }
    }
};