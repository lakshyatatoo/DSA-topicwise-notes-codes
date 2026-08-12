#include <bits/stdc++.h>
using namespace std;
// brute
class Solution
{
public:
    void bubbleSort(vector<int> &arr)
    {
        // code here
        int n = arr.size();
        for (int i = n - 1; i >= 1; i--)
        {
            int flag = 0;
            for (int j = 0; j < i; j++)
            {
                if (arr[j] > arr[j + 1])
                {
                    swap(arr[j], arr[j + 1]);
                    flag = 1;
                }
            }
            if (flag == 0)
            {
                break;
            }
        }
    }
};