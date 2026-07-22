#include <bits/stdc++.h>
using namespace std;

// brute
string longestCommonPrefix(vector<string> &strs)
{
    if (strs.size() == 1)
        return strs[0];
    string res = "";
    for (int i = 0; i < strs[0].size(); i++)
    {
        char c = strs[0][i];
        for (int j = 1; j < strs.size(); j++)
        {
            if (i >= strs[j].size() || strs[j][i] != c)
            {
                return res;
            }
        }
        res += c;
    }
    return res;
}

// optimal
string longestCommonPrefix(vector<string> &strs)
{
    if (strs.size() == 1)
        return strs[0];
    sort(strs.begin(), strs.end());
    string a = strs[0];
    string b = strs[strs.size() - 1];
    string res = "";
    for (int i = 0; i < a.size(); i++)
    {
        if (a[i] == b[i])
        {
            res += a[i];
        }
        else
        {
            break;
        }
    }
    return res;
}