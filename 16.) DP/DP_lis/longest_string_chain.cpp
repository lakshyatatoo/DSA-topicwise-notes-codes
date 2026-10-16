#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    bool compare(string &a, string &b)
    {
        if (a.size() != b.size() + 1)
            return false;
        int i = 0, j = 0;
        while (i < a.size())
        {
            if (j < b.size() && a[i] == b[j])
                i++, j++;
            else
                i++;
        }
        return (i == a.size() && j == b.size());
    }
    int longestStrChain(vector<string> &words)
    {
        sort(words.begin(), words.end(), [](string &a, string &b)
             { return a.size() < b.size(); });
        int n = words.size(), maxi = -1, lastind = -1;
        vector<int> dp(n, 1), hsh(n);
        for (int i = 0; i < n; i++)
        {
            hsh[i] = i;
            for (int prev = 0; prev < i; prev++)
            {
                if ((compare(words[i], words[prev]) && 1 + dp[prev] > dp[i]))
                    dp[i] = 1 + dp[prev], hsh[i] = prev;
            }
            if (dp[i] > maxi)
                maxi = dp[i], lastind = i;
        }
        // for printing
        vector<string> lis(maxi);
        int j = maxi - 1;
        while (hsh[lastind] != lastind)
            lis[j--] = words[lastind], lastind = hsh[lastind];
        lis[j] = words[lastind];
        return maxi;
    }
};
