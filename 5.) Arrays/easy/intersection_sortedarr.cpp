#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    vector<int> intersection(vector<int> &a, vector<int> &b)
    {
        int n = a.size();
        int m = b.size();
        int i = 0;
        int j = 0;
        vector<int> ans;
        while (i < n && j < m)
        {
            if (a[i] < b[j])
            {
                i++;
            }
            else if (b[j] < a[i])
            {
                j++;
            }
            else
            {
                if (ans.size() == 0 || ans.back() != a[i])
                {
                    ans.push_back(a[i]);
                    i++;
                    j++;
                }
            }
        }
        return ans;
    }
};