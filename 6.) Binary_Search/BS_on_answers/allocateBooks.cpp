#include <bits/stdc++.h>
using namespace std;

// BRUTE LINEAR SEARCH + allocate possible //tle
class Solution
{
public:
    int allocPossible(vector<int> &arr, int pages, int n)
    {

        int student = 1;
        long long pagesWithStudent = 0;
        for (int i = 0; i < n; i++)
        {
            if (pagesWithStudent + arr[i] <= pages)
            {
                pagesWithStudent += arr[i];
            }
            else
            {
                student++;
                pagesWithStudent = arr[i];
            }
        }
        return student;
    }
    int findPages(vector<int> &arr, int k)
    {
        // code here

        int n = arr.size();
        if (k > n) // if students are more than books
            return -1;
        long long low = *max_element(arr.begin(), arr.end());     // max element
        long long high = accumulate(arr.begin(), arr.end(), 0LL); // sum of all elements
        for (long long i = low; i <= high; i++)
        {
            int cnt = allocPossible(arr, i, n);
            if (cnt <= k) // because we have to minimize the max no of pages and the decrease is not linear it may jump from 6 to 4 so when it goes from 6 to 4 it will miss 5 so we have to take <= and then with <=k ts possible so it will be possible by k too so answer accepts
                return i;
        }
        return -1;
    }
};

// /// binary search + allocate possible
class Solution
{
public:
    int allocPossible(vector<int> &arr, int pages, int n)
    {

        int student = 1;
        long long pagesWithStudent = 0;
        for (int i = 0; i < n; i++)
        {
            if (pagesWithStudent + arr[i] <= pages)
            {
                pagesWithStudent += arr[i];
            }
            else
            {
                student++;
                pagesWithStudent = arr[i];
            }
        }
        return student;
    }
    int findPages(vector<int> &arr, int k)
    {
        // code here

        int n = arr.size();
        if (k > n) // if students are more than books
            return -1;
        long long low = *max_element(arr.begin(), arr.end());     // max element
        long long high = accumulate(arr.begin(), arr.end(), 0LL); // sum of all elements
        while (low <= high)
        {
            long long mid = low + (high - low) / 2;
            int cnt = allocPossible(arr, mid, n);
            if (cnt > k)
            {
                low = mid + 1;
            }
            else
            {
                high = mid - 1;
            }
        }
        return low;
    }
};
