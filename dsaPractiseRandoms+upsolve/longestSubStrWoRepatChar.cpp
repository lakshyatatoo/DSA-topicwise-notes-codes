#include <bits/stdc++.h>
using namespace std;

// brute force approach
// tc: O(n^3) sc: O(n)
// tle

class Solution
{
public:
    bool isOg(string s)
    {
        sort(s.begin(), s.end());
        for (int i = 0; i < s.size() - 1; i++)
        {
            if (s[i] == s[i + 1])
                return false;
        }
        return true;
    }
    int lengthOfLongestSubstring(string s)
    {
        if (s.size() == 0)
            return 0;
        int cnt = 0;
        for (int i = 0; i < s.size(); i++)
        {
            for (int j = i; j < s.size(); j++)
            {

                if (isOg(s.substr(i, j - i + 1)))
                {
                    cnt = max(cnt, j - i + 1);
                }
            }
        }
        return cnt;
    }
};

// optimal
class Solution
{
public:
    int lengthOfLongestSubstring(string s)
    {
        unordered_map<int, int> mp;
        int r = 0;
        int l = 0;
        int cnt = 0;
        while (r < s.size())
        {
            while (mp[s[r]] > 0)
            {
                mp[s[l]]--;
                l++;
            }
            mp[s[r]]++;
            cnt = max(cnt, r - l + 1);
            r++;
        }
        return cnt;
    }
};