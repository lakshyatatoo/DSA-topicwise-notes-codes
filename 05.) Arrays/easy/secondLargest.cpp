#include <bits/stdc++.h>
using namespace std;
// Brute Force
class Solution
{
public:
    int getSecondLargest(vector<int> &arr)
    {
        int n = arr.size();

        sort(arr.begin(), arr.end());

        int largest = arr[n - 1];
        int secondLargest = -1;

        for (int i = n - 2; i >= 0; i--)
        {
            if (arr[i] != largest)
            {
                secondLargest = arr[i];
                break;
            }
        }

        return secondLargest;
    }
};

// Better
class Solution
{
public:
    int getSecondLargest(vector<int> &arr)
    {
        int n = arr.size();

        int largest = arr[0];

        // Find largest
        for (int i = 0; i < n; i++)
        {
            if (arr[i] > largest)
            {
                largest = arr[i];
            }
        }

        int secondLargest = -1;

        // Find second largest
        for (int i = 0; i < n; i++)
        {
            if (arr[i] > secondLargest && arr[i] != largest)
            {
                secondLargest = arr[i];
            }
        }

        return secondLargest;
    }
};

// optimal
class Solution
{
public:
    int getSecondLargest(vector<int> &arr) // optimal
    {
        int n = arr.size();

        int largest = arr[0];
        int sLargest = -1;
        for (int i = 0; i < n; i++)
        {
            if (arr[i] > largest)
            {
                sLargest = largest;
                largest = arr[i];
            }
            else if (arr[i] > sLargest && arr[i] != largest)
            {
                sLargest = arr[i];
            }
        }

        return sLargest;
    }
};