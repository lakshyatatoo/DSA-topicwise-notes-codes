#include <bits/stdc++.h>
using namespace std;

// brute. -- can use map too
class Solution
{
public:
    int longestKSubstr(string &s, int k)
    {
        int n = s.size();
        int maxLen = 0;
        for (int i = 0; i < n; i++)
        {
            set<char> st;
            for (int j = i; j < n; j++)
            {
                st.insert(s[j]);
                if (st.size() <= k)
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
    int longestKSubstr(string &s, int k)
    {
        int l = 0, r = 0, maxLen = 0, n = s.size();
        unordered_map<char, int> mp;
        while (r < n)
        {
            mp[s[r]]++;
            while (mp.size() > k)
            {
                mp[s[l]]--;
                if (mp[s[l]] == 0)
                {
                    mp.erase(s[l]);
                }
                l++;
            }
            if (mp.size() <= k)
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
    int longestKSubstr(string &s, int k)
    {
        int l = 0, r = 0, maxLen = 0, n = s.size();
        unordered_map<char, int> mp;
        while (r < n)
        {
            mp[s[r]]++;
            if (mp.size() > k)
            {
                mp[s[l]]--;
                if (mp[s[l]] == 0)
                {
                    mp.erase(s[l]);
                }
                l++;
            }
            if (mp.size() <= k)
            {
                maxLen = max(maxLen, r - l + 1);
            }
            r++;
        }
        if (mp.size() < k)
            return -1; // extra check for edge case.
        return maxLen;
    }
};
