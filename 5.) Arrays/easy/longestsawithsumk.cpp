#include <bits/stdc++.h>
using namespace std;
// brute(generating all subarrays) for +ves only
//  from o(n^3) to o(n^2)
class Solution
{
public:
    int longestSubarray(vector<int> &arr, int k)
    {
        // code here
        int sum = 0;
        int n = arr.size();
        int mL = 0;
        for (int i = 0; i < n; i++)
        {
            for (int j = i; j < n; j++)
            {
                sum += arr[j];
                if (sum == k)
                {
                    mL = max(mL, j - i + 1);
                }
                // o(n^3)
                //  sum=0;
                //  for(k=i;k<j;k++){
                //      sum+=a[k];
                //  }
                //  if(sum==k){
                //      maxLen=max(maxLen,j-i+1);
                //  }
            }
        }
        return mL;
    }
};

// better (hashing) for +ves and -ves and 0; just use unordered_map for -ves for 0 just use map but check for same sum
class Solution
{
public:
    int longestSubarray(vector<int> &arr, int k)
    {
        // code here
        int sum = 0;
        int n = arr.size();
        int ml = 0;
        int len = 0;
        unordered_map<long long, int> mp;
        for (int i = 0; i < n; i++)
        {
            sum += arr[i];
            //
            if (sum == k)
            { // for if total is k
                ml = max(ml, i + 1);
            }

            int rem = sum - k;
            // if rem in map find its lenght
            if (mp.find(rem) != mp.end())
            {

                ml = max(ml, i - mp[rem]);
            }
            // not storing same sum again
            if (mp.find(sum) == mp.end())
            {
                mp[sum] = i;
            }
        }
        return ml;
    }
};

// optimal(for +ves and zeros)
class Solution
{
public:
    int longestSubarray(vector<int> &a, int k)
    {
        // code here
        int n = a.size();
        int l = 0, r = 0;
        int sum = a[0];
        int ml = 0;
        while (r < n)
        {

            //
            while (l <= r && sum > k)
            {
                sum -= a[l];
                l++;
            }
            //
            if (sum == k)
            {
                ml = max(ml, r - l + 1);
            }
            //

            sum += a[r];
            r++;
        }
        return ml;
    }
};
