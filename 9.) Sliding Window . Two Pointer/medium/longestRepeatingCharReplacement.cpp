#include <bits/stdc++.h>
using namespace std;

/// brute -- len-maxFreq <=k thne maxLen update
// tle tle
class Solution
{
public:
    int characterReplacement(string s, int k)
    {
        int n = s.size();
        int maxLen = 0;
        for (int i = 0; i < n; i++)
        {
            vector<int> hsh(26, 0);
            int maxFreq = 0;
            for (int j = i; j < n; j++)
            {
                hsh[s[j] - 'A']++;
                maxFreq = max(maxFreq, hsh[s[j] - 'A']);
                int changes = (j - i + 1) - maxFreq;
                if (changes <= k)
                {
                    maxLen = max(maxLen, j - i + 1);
                }
                else
                    break;
            }
        }
        return maxLen;
    }
};

// better
class Solution
{
public:
    int characterReplacement(string s, int k)
    {
        int n = s.size(), maxLen = 0, l = 0, r = 0, maxFreq = 0;
        vector<int> hsh(26, 0);
        while (r < n)
        {
            hsh[s[r] - 'A']++;
            maxFreq = max(maxFreq, hsh[s[r] - 'A']);

            while ((r - l + 1) - maxFreq > k)
            {
                hsh[s[l] - 'A']--;
                for (int i = 0; i < 26; i++)
                {
                    maxFreq = max(maxFreq, hsh[i]);
                }
                l++;
            }
            if ((r - l + 1) - maxFreq <= k)
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
    int characterReplacement(string s, int k)
    {
        int n = s.size(), maxLen = 0, l = 0, r = 0, maxFreq = 0;
        vector<int> hsh(26, 0);
        while (r < n)
        {
            hsh[s[r] - 'A']++;
            maxFreq = max(maxFreq, hsh[s[r] - 'A']);

            if ((r - l + 1) - maxFreq > k)
            {
                hsh[s[l] - 'A']--;
                l++;
            }
            if ((r - l + 1) - maxFreq <= k)
            {
                maxLen = max(maxLen, r - l + 1);
            }
            r++;
        }
        return maxLen;
    }
};
