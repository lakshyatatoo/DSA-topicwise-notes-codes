#include <bits/stdc++.h>
using namespace std;
// // brute 2loops tle
class Solution {
  public:
    int inversionCount(vector<int> &arr) {
        // Code Here
        int cnt=0;
        int n=arr.size();
        for(int i=0;i<n;i++){
            for(int j=i+1;j<n;j++){
                if(arr[i]>arr[j]){
                cnt++;}
            }
        }
        return cnt;
    }
};

// optimal. using merge sort approach
// while merging if element from right array is smaller than left array then all the remaining elements in left array will form an inversion with this element
// so we can count them as mid - left + 1
class Solution
{

public:
    int merge(vector<int> &arr, int low, int mid, int high) // for cnt int
    {

        vector<int> temp;
        int left = low;
        int right = mid + 1;

        int cnt = 0;
        while (left <= mid && right <= high)
        {
            if (arr[left] <= arr[right])
            {
                temp.push_back(arr[left]);
                left++;
            }
            else
            {
                cnt += mid - left + 1;
                temp.push_back(arr[right]);
                right++;
            }
        }
        while (left <= mid)
        {
            temp.push_back(arr[left]);
            left++;
        }
        while (right <= high)
        {
            temp.push_back(arr[right]);
            right++;
        }

        for (int i = low; i <= high; i++)
        {
            arr[i] = temp[i - low];
        }
        return cnt;
    }

public:
    int mergeSort(vector<int> &arr, int low, int high)
    {
        int cnt = 0;

        // code here
        if (low >= high)
        {
            return cnt;
        }

        int mid = (low + high) / 2;

        cnt += mergeSort(arr, low, mid);      // whatever the did at merge from base recursion stage that cnt is return from the merge
        cnt += mergeSort(arr, mid + 1, high); // every tiem mergesort a merge is performed
        cnt += merge(arr, low, mid, high);
        return cnt;
    }

public:
    int inversionCount(vector<int> &arr)
    {
        // Code Here
        int n = arr.size();
        return mergeSort(arr, 0, n - 1); // return added for cnt
        // return cnt; omitted
    }
};
