#include <bits/stdc++.h>
using namespace std;

// brute
class Solution
{
public:
    string minWindow(string s, string t)
    {
        int minLen = INT_MAX, start = -1;
        for (int i = 0; i < s.size(); i++)
        {
            vector<int> hsh(256, 0);
            int cnt = 0;
            for (int j = 0; j < t.size(); j++)
            {
                hsh[t[j]]++;
            }
            for (int j = i; j < s.size(); j++)
            {
                if (hsh[s[j]] > 0)
                {
                    cnt++;
                }
                hsh[s[j]]--;
                if (cnt == t.size())
                {
                    if (j - i + 1 < minLen)
                    {
                        minLen = j - i + 1;
                        start = i;
                        break;
                    }
                }
            }
        }
        if (start == -1)
            return "";

        return s.substr(start, minLen);
    }
};

// optimal
class Solution
{
public:
    string minWindow(string s, string t)
    {
        int minLen = INT_MAX, start = -1, cnt = 0, l = 0, r = 0;
        vector<int> hsh(256, 0);
        for (int i = 0; i < t.size(); i++)
        {
            hsh[t[i]]++;
        }
        while (r < s.size())
        {
            if (hsh[s[r]] > 0)
                cnt++;
            hsh[s[r]]--;

            while (cnt == t.size())
            {
                if (r - l + 1 < minLen)
                {
                    minLen = r - l + 1;
                    start = l;
                }

                hsh[s[l]]++;
                if (hsh[s[l]] > 0)
                    cnt--;
                l++;
            }
            r++;
        }
        if (start == -1)
            return "";

        return s.substr(start, minLen);
    }
};