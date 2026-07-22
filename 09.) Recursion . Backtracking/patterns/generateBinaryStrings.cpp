#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    void generateSubSequences(int i, vector<string> &ds, string &s, int n)
    {
        if (i == n)
        {
            ds.push_back(s);
            return;
        }
        s[i] = '0';
        generateSubSequences(i + 1, ds, s, n);
        s[i] = '1';
        generateSubSequences(i + 1, ds, s, n);
    }
    vector<string> binstr(int n)
    {
        string s(n, '0');
        vector<string> ds;
        generateSubSequences(0, ds, s, n);
        return ds;
    }
};