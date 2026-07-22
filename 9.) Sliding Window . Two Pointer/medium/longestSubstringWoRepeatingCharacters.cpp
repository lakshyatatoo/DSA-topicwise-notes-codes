#include <bits/stdc++.h>
using namespace std;

// brute;
class Solution
{
public:
    int lengthOfLongestSubstring(string s)
    {
        int n = s.size();
        int maxLen = 0;
        for (int i = 0; i < n; i++)
        {
            vector<int> hsh(256, 0);
            for (int j = i; j < n; j++)
            {
                if (hsh[s[j]] == 1)
                    break;
                maxLen = max(maxLen, j - i + 1);
                hsh[s[j]] = 1;
            }
        }
        return maxLen;
    }
};

// optimal;
class Solution
{
public:
    int lengthOfLongestSubstring(string s)
    {
        vector<int> hsh(256, -1);
        int l = 0, r = 0, maxLen = 0;
        int n = s.size();
        if (n == 0)
            return 0;
        while (r < n)
        {
            if (hsh[s[r]] != -1)
            {
                if (hsh[s[r]] >= l)
                {
                    l = hsh[s[r]] + 1;
                }
            }
            maxLen = max(maxLen, r - l + 1);
            hsh[s[r]] = r;
            r++;
        }
        return maxLen;
    }
};