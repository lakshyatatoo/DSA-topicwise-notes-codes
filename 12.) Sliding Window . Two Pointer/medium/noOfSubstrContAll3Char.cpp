#include <bits/stdc++.h>
using namespace std;

// brute tle
class Solution
{
public:
    int numberOfSubstrings(string s)
    {
        int n = s.size();
        int cnt = 0;
        for (int i = 0; i < n; i++)
        {
            vector<int> hsh(3, 0);
            for (int j = i; j < n; j++)
            {
                hsh[s[j] - 'a'] = 1;
                if (hsh[0] + hsh[1] + hsh[2] == 3)
                    cnt++;
            }
        }
        return cnt;
    }
};

// better tle
class Solution
{
public:
    int numberOfSubstrings(string s)
    {
        int n = s.size();
        int cnt = 0;
        for (int i = 0; i < n; i++)
        {
            vector<int> hsh(3, 0);
            for (int j = i; j < n; j++)
            {
                hsh[s[j] - 'a'] = 1;
                if (hsh[0] + hsh[1] + hsh[2] == 3)
                {
                    cnt += n - j;
                    break;
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
    int numberOfSubstrings(string s)
    {
        int n = s.size();
        vector<int> lastSeen(n, -1);
        int cnt = 0;
        for (int i = 0; i < n; i++)
        {
            lastSeen[s[i] - 'a'] = i;
            if (lastSeen[0] != -1 && lastSeen[1] != -1 && lastSeen[2] != -1)
            {
                cnt += 1 + min({lastSeen[0], lastSeen[1], lastSeen[2]});
            }
        }
        return cnt;
    }
};