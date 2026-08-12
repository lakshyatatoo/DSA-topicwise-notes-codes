#include <bits/stdc++.h>
using namespace std;

// optimal
class Solution
{
public:
    bool searchInSorted(vector<int> &arr, int k)
    {
        // code here
        for (int i = 0; i < arr.size(); i++)
        {
            if (arr[i] == k)
            {
                return true;
            }
        }
        return false;
    }
};