#include <bits/stdc++.h>
using namespace std;



//brute backtracking solution tle.  do dp
class Solution
{
public:
    bool solve(int index, string &s, vector<string> &wordDict)
    {
        if (index == s.size())
        {
            return true;
        }

        // Trying every word in the dictionary
        for (string &word : wordDict)
        {
            int len = word.size();

            // Checking whether this word matches starting at 'index'
            if (index + len <= s.size() &&
                s.substr(index, len) == word)
            {

                // Recursively solving for the remaining substring
                if (solve(index + len, s, wordDict))
                {
                    return true;
                }
            }
        }
        return false;
    }

    bool wordBreak(string s, vector<string> &wordDict)
    {
        return solve(0, s, wordDict);
    }
};