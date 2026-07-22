#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    string removeKdigits(string num, int k)
    {
        stack<char> st;
        for (char c : num)
        {
            while (!st.empty() && k > 0 && (st.top() - '0') > (c - '0'))
            {
                st.pop();
                k--;
            }
            st.push(c);
        }
        while (k > 0)
        {
            st.pop();
            k--;
        }
        if (st.empty())
            return "0";
        string res = "";
        while (!st.empty())
        {
            res += st.top();
            st.pop();
        }
        while (res.size() && res.back() == '0')
            res.pop_back();
        if (res.empty())
            return "0";
        reverse(res.begin(), res.end());
        return res;
    }
};