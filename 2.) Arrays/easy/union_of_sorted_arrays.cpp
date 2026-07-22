#include <bits/stdc++.h>
using namespace std;
// brute
class Solution
{
public:
    vector<int> findUnion(vector<int> &a, vector<int> &b)
    {
        // code here
        set<int> st;
        for (int i = 0; i < a.size(); i++)
        {
            st.insert(a[i]);
        }
        for (int i = 0; i < b.size(); i++)
        {
            st.insert(b[i]);
        }
        vector<int> unn(st.size());
        int i = 0;
        for (auto it : st)
        {
            unn[i] = it;
            i++;
        }

        return unn;
    }
};

// optimal
class Solution
{
public:
    vector<int> findUnion(vector<int> &a, vector<int> &b)
    {
        // code here
        int n1 = a.size();
        int n2 = b.size();
        int i = 0;
        int j = 0;
        vector<int> ua;
        while (i < n1 && j < n2)
        {
            if (a[i] <= b[j])
            {
                if (ua.size() == 0 || ua.back() != a[i])
                {
                    ua.push_back(a[i]);
                }
                i++;
            }
            else
            {
                if (ua.size() == 0 || ua.back() != b[j])
                {
                    ua.push_back(b[j]);
                }
                j++;
            }
        }
        while (i < n1)
        {
            if (ua.size() == 0 || ua.back() != a[i])
            {
                ua.push_back(a[i]);
            }
            i++;
        }
        while (j < n2)
        {
            if (ua.size() == 0 || ua.back() != b[j])
            {
                ua.push_back(b[j]);
            }
            j++;
        }
        return ua;
    }
};