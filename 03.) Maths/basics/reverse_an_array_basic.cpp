#include <bits/stdc++.h>
using namespace std;

// brute using a temp array and then reversing it
class Solution
{
public:
    void reverseArray(vector<int> &arr)
    {
        int n = arr.size();
        vector<int> temp;
        for (int i = n - 1; i >= 0; i--)
        {
            temp.push_back(arr[i]);
        }
        for (int i = 0; i < n; i++)
        {
            arr[i] = temp[i];
        }
    }
};
// optimal in place
class Solution
{
public:
    void reverseArray(vector<int> &arr)
    {
        int n = arr.size();

        int a = 0;
        int b = n - 1;

        while (a < b)
        {
            swap(arr[a], arr[b]);

            a++;
            b--;
        }
    }
};
