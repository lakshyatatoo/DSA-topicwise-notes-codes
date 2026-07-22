#include <bits/stdc++.h>
using namespace std;

// brute
class Solution
{
public:
    int totalFruit(vector<int> &fruits)
    {
        int n = fruits.size();
        int maxLen = 0;
        for (int i = 0; i < n; i++)
        {
            set<int> st;
            for (int j = i; j < n; j++)
            {
                st.insert(fruits[j]);
                if (st.size() <= 2)
                {
                    maxLen = max(maxLen, j - i + 1);
                }
                else
                {
                    break;
                }
            }
        }
        return maxLen;
    }
};

// better
class Solution
{
public:
    int totalFruit(vector<int> &fruits)
    {
        int l = 0, r = 0, maxLen = 0, n = fruits.size();
        unordered_map<int, int> mp;
        while (r < n)
        {
            mp[fruits[r]]++;
            while (mp.size() > 2)
            {
                mp[fruits[l]]--;
                if (mp[fruits[l]] == 0)
                {
                    mp.erase(fruits[l]);
                }
                l++;
            }
            if (mp.size() <= 2)
            {
                maxLen = max(maxLen, r - l + 1);
            }
            r++;
        }
        return maxLen;
    }
};

// optimal
class Solution
{
public:
    int totalFruit(vector<int> &fruits)
    {
        int l = 0, r = 0, maxLen = 0, n = fruits.size();
        unordered_map<int, int> mp;
        while (r < n)
        {
            mp[fruits[r]]++;
            if (mp.size() > 2)
            {
                mp[fruits[l]]--;
                if (mp[fruits[l]] == 0)
                {
                    mp.erase(fruits[l]);
                }
                l++;
            }
            if (mp.size() <= 2)
            {
                maxLen = max(maxLen, r - l + 1);
            }
            r++;
        }
        return maxLen;
    }
};